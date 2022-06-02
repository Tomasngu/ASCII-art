#include"CVideoHandler.h"

CVideoHandler::CVideoHandler(CVideo & video)
:m_Video(video)
{}

void CVideoHandler::start(void) {
    if(m_Video.getSize() > 0) m_Video.getFrame(lastShownframe).render();
    showHelp();
    while(true){
        try{
            std::cout << std::endl << "Command: "; 
            std::string command = ArgLoader::getString();
            if(command == "help"){
                m_Video.getFrame(lastShownframe).render();
                showHelp();    
            }
            else if(command == "add"){
                addFrame();  
                m_Video.getFrame(lastShownframe).render();
            }
            else if(command == "remove"){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No frames loaded.");
                removeFrame();
                if(m_Video.getSize() > 0) m_Video.getFrame(lastShownframe).render();
            }
            else if(command == "play"){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No images loaded.");
                m_Video.play();
            }
            else if(command == "switch"){
                if(m_Video.getSize() <= 1) throw std::invalid_argument("Not enough images loaded.");
                switchFrames();
                m_Video.getFrame(lastShownframe).render();
            }
            else if(command == "show"){
                if(m_Video.getSize() == 0) throw std::invalid_argument("No images loaded.");
                showFrame();
                m_Video.getFrame(lastShownframe).render();
            }
            else{
                throw std::invalid_argument(command + " does not exist.");
            }
        }
        catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv) || e . what () ==  ("Exited."sv)  ){
                throw std::invalid_argument("Exited.");
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
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
            removed = true;
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
            switched = true;
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
