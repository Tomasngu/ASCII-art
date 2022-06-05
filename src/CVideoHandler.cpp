/**
 * @file CVideoHandler.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include"CVideoHandler.h"

CVideoHandler::CVideoHandler(CVideo & video)
:m_Video(std::move(video))
{}

void CVideoHandler::start(void) {
    if(m_Video.getSize() > 0) m_Video.getFrame(lastShownframe).render();
    showHelp();
    while(true){
        try{
            std::cout << std::endl << "Command: "; 
            std::string command = ArgLoader::getString();
            if(command == CMD_BACK){
                return;
            }
            else if(command == CMD_HELP){
                if(m_Video.getSize() > 0) m_Video.getFrame(lastShownframe).render();
                showHelp();    
            }
            else if(command == CMD_ADD){
                addFrame();  
                m_Video.getFrame(lastShownframe).render();
            }
            else if(command == CMD_REMOVE){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No images loaded.");
                removeFrame();
            }
            else if(command == CMD_PLAY){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No images loaded.");
                m_Video.play();
            }
            else if(command == CMD_SWITCH){
                if(m_Video.getSize() <= 1) throw std::invalid_argument("Not enough images loaded.");
                switchFrames();
            }
            else if(command == CMD_SHOW){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No images loaded.");
                showFrame();
                m_Video.getFrame(lastShownframe).render();
            }
            else{
                throw std::invalid_argument(command + " does not exist.");
            }
        }
        catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}


void CVideoHandler::showHelp(void) const {
    std::cout << 
    R"(List of avalaible commands: 
        play        -   plays animation. 
        add         -   add new frame. 
        remove      -   remove frame.
        show        -   show given frame.
        switch      -   switch given frames.

        help        -   prints this help menu. 
        back        -   go back to main menu. )"
    << std::endl;
}

void CVideoHandler::addFrame(void){
    bool ImageSet = false;
    while(!ImageSet){
        try{
            std::cout << "Enter path to file: ";
            std::string path = ArgLoader::getString();
            CFileLoader check(path);
            std::string type = check.checkImage();
            if(type != "file") throw std::invalid_argument(path + " is not a file.");
            CImage image = check.getImage();
            m_Video.addFrame(image);
            lastShownframe = (int) (m_Video.getSize() - 1);
            ImageSet = true;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}
void CVideoHandler::removeFrame(void){
    bool removed = false;
    while(!removed){
        try{
            std::cout << "Enter index of a frame you want to remove." << std::endl;
            printAllowedIndexes();
            int index = ArgLoader::getNums(1)[0];
            m_Video.removeFrame(index);
            lastShownframe = 0;
            std::cout << ANSI_CLEAR;
            std::cout << "Frame at index " << index << " removed." << std::endl;
            removed = true;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}
void CVideoHandler::switchFrames(void){
    bool switched = false;
    while(!switched){
        try{
            std::cout << "Enter indexes of two frames you want to switch." << std::endl;
            printAllowedIndexes();
            std::vector<int> nums = ArgLoader::getNums(2);
            m_Video.switchframes(nums[0], nums[1]);
            std::cout << ANSI_CLEAR;
            std::cout << "Frames at index " << nums[0] <<" and " << nums[1] << " switched." << std::endl;
            switched = true;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}
void CVideoHandler::showFrame(void) {
    bool shown = false;
    while(!shown){
        try{
            std::cout << "Enter index of a frame you want to show." << std::endl;
            printAllowedIndexes();
            int index = ArgLoader::getNums(1)[0];
            CImage image =  m_Video.getFrame(index);
            image.render();
            lastShownframe = index;
            shown = true;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}

void CVideoHandler::printAllowedIndexes(void) const{
    if(m_Video.getSize() != 1){
        std::cout << "Allowed indexes are 0 - " << m_Video.getSize() - 1<< std::endl;
    }else{
        std::cout << "Only Allowed index is 0" << std::endl;
    } 
}
