/**
 * @file CImageHandler.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CImageHandler.h"

CImageHandler::CImageHandler(const CImage & image):
m_Image(image)
{}

std::map<std::string, std::shared_ptr<CFilter>> CImageHandler::Commands =   {{CMD_ROTATER, std::make_shared<CFilterRotateR>(CFilterRotateR())},
                                                                            {CMD_ROTATEL, std::make_shared<CFilterRotateL>(CFilterRotateL())},
                                                                            {CMD_MIRROR , std::make_shared<CFilterMirror>(CFilterMirror())},
                                                                            {CMD_FLIP , std::make_shared<CFilterFlip>(CFilterFlip())},
                                                                            {CMD_BRIGHT , std::make_shared<CFilterBright>(CFilterBright())},
                                                                            {CMD_DARK  , std::make_shared<CFilterDark>(CFilterDark())},
                                                                            {CMD_INVERT , std::make_shared<CFilterInverse>(CFilterInverse())},
                                                                            {CMD_UPSIZE , std::make_shared<CFilterResize>(CFilterResize(UpScale))},
                                                                            {CMD_DOWNSIZE , std::make_shared<CFilterResize>(CFilterResize(DownScale))}
                                                                            };

void CImageHandler::start(void){
    showHelp();
    while(true){
        try{
            std::cout << std::endl << "Command: "; 
            std::string command = ArgLoader::getString();
            if(command == CMD_BACK){
                return;
            }
            else if(command == CMD_HELP){
                m_Image.render();
                showHelp();    
            }
            else if(command == CMD_TRANSITION){
                loadTransition();
                m_Image.render();
            }
            else if(command == CMD_CUSTOM){
                createCustom();
                m_Image.render();
                std::cout << "Custom filter made successfully. Check out help." << std::endl;
            }
            else if(Commands.find(command) != Commands.end()){
                Commands[command]->edit(m_Image); //Polymorphism
                m_Image.render();
            }
            else if(m_CustomSet && m_CustomCommands.find(command) != m_CustomCommands.end()){
                for(const auto & com : m_CustomCommands[command]){
                    com.second->edit(m_Image);
                }
                m_Image.render();
            }
            else{
                throw std::invalid_argument(command + " does not exist.");
            }
        }
        catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            m_Image.render();
            std::cout << e.what() << std::endl;
        }
    }
}

void CImageHandler::loadTransition(void){
    bool TransitionSet = false;
    while(!TransitionSet){
        try{
            std::cout << "Choose \"type\" if you want to type the transition yourself." << std::endl;
            std::cout << "Choose \"file\" if you want to load the transition from file." << std::endl;
            std::string command = ArgLoader::getString();
            if(command == TYPE_t || command == FILE_t){
                loadTransitionWord(command);
                TransitionSet = true;
            }
            else{
                throw std::invalid_argument("Command " + command + " not found.");
            }
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}

void CImageHandler::loadTransitionWord(const std::string & keyword){
    bool TransitionSet = false;
    while(!TransitionSet){
        try{
            if(keyword == TYPE_t){
                m_Image.loadTransitionType();
                TransitionSet = true;
            }
            if(keyword == FILE_t){
                m_Image.loadTransitionFile();
                TransitionSet = true;
            }
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
}   

void CImageHandler::createCustom(void){
    std::vector<std::pair<std::string,std::unique_ptr<CFilter>>> filterList;
    const std::string name = loadName();
    while(true){
        try{
            std::cout << "Enter your commands separated by whitespace." << std::endl;
            std::string line = ArgLoader::getLine();       
            std::stringstream ss(line);
            if(ss.str().empty()) throw std::invalid_argument("No commands given.");
            std::string com;
            while(ss >> com){
                if(Commands.find(com) != Commands.end()){
                    filterList.emplace_back(com, Commands[com]->clone());
                }
                else{
                    filterList.clear();
                    throw std::invalid_argument(com + " not found.");
                }
            }
            break;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
    m_CustomCommands[name] = std::move(filterList);
    m_CustomSet = true;
}

const std::string CImageHandler::loadName(void) const{
    std::string name;
    while(true){
        try{
            std::cout << "Enter name of your custom command." << std::endl;
            name = ArgLoader::getString();
            if(Commands.find(name) != Commands.end() || (m_CustomSet && m_CustomCommands.find(name) != m_CustomCommands.end()) 
                ||  name ==  CMD_CUSTOM ||  name ==  CMD_BACK||   name == CMD_TRANSITION  || name ==  CMD_HELP){
                throw std::invalid_argument("Command " + name + " already exists.");
            }   
            break;
        }catch ( const std::invalid_argument & e ){
            if(e . what () ==  (EXITED_sv)  ){
                throw std::invalid_argument(EXITED);
            }
            std::cout << e.what() << std::endl;
        }
    }
    return name;
}

void CImageHandler::printCustoms(void) const{
    std::cout << "Custom commands:" << std::endl;
    for(const auto & custom: m_CustomCommands){
        std::cout << "\t" <<  custom.first << "     -   ";
        for(auto it = custom.second.begin(); it != custom.second.end(); ++it){
            std::cout << it->first;
            if(std::next(it) != custom.second.end()) std::cout << " + ";
        }  
        std::cout << std::endl;
    }
}

void CImageHandler::showHelp(void) const{
    std::cout << 
    R"(List of available commands: 
        rotateR     -   rotates image 90° to the right.
        rotateL     -   rotates image 90° to the left.
        mirror      -   mirrors the image.
        flip        -   flips the image upside down.
        invert      -   inverts grayscale colors.
        bright      -   makes the image brighter.
        dark        -   makes the image darker.
        upsize      -   makes the image larger.
        downsize    -   makes the image smaller.
        
        custom      -   create custom filter.
        transition  -   load custom ASCII transition.
        help        -   prints this help menu. 
        back        -   go back to main menu. )"
    << std::endl;
    if(m_CustomSet) printCustoms();
}
