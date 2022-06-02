#include "CImageHandler.h"

CImageHandler::CImageHandler(CImage & image):
m_Image(image)
{}

std::map<std::string, std::shared_ptr<CFilter>> CImageHandler::Commands =   {{"rotateR", std::make_shared<CFilterRotateR>(CFilterRotateR())},
                                                                            {"rotateL", std::make_shared<CFilterRotateL>(CFilterRotateL())},
                                                                            {"mirror" , std::make_shared<CFilterMirror>(CFilterMirror())},
                                                                            {"flip" , std::make_shared<CFilterFlip>(CFilterFlip())},
                                                                            {"bright" , std::make_shared<CFilterBright>(CFilterBright())},
                                                                            {"dark" , std::make_shared<CFilterDark>(CFilterDark())},
                                                                            {"invert" , std::make_shared<CFilterInverse>(CFilterInverse())},
                                                                            {"upsize" , std::make_shared<CFilterResize>(CFilterResize(1.2))},
                                                                            {"downsize" , std::make_shared<CFilterResize>(CFilterResize(0.8))}
                                                                            };

void CImageHandler::start(void){
    showHelp();
    while(true){
        try{
            std::cout << std::endl << "Command: "; 
            std::string command = ArgLoader::getString();
            if(command == "back"){
                return;
            }
            else if(command == "help"){
                m_Image.render();
                showHelp();    
            }
            else if(command == "transition"){
                loadTransition();
                m_Image.render();
            }
            else if(command == "custom"){
                createCustom();
                m_Image.render();
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
                // m_Image.render();
                throw std::invalid_argument(command + " does not exist.");
            }
        }
        catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv) || e . what () ==  ("Exited."sv)  ){
                throw std::invalid_argument("Exited.");
            }
            m_Image.render();
            std::cout << e.what() << std::endl;
        }
    }
}

void CImageHandler::loadTransition(void) const{
    bool TransitionSet = false;
    while(!TransitionSet){
        try{
            std::cout << "Choose \"type\" if you want to type the transition yourself." << std::endl;
            std::cout << "Choose \"file\" if you want to load the transition from file." << std::endl;
            std::string command = ArgLoader::getString();
            if(command == "type" || command == "file"){
                loadTransitionWord(command);
                TransitionSet = true;
            }
            else{
                throw std::invalid_argument("Command " + command + " not found.");
            }
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
            }
            std::cout << e.what() << std::endl;
        }
    }
}

void CImageHandler::loadTransitionWord(const std::string & keyword) const{
    bool TransitionSet = false;
    while(!TransitionSet){
        try{
            if(keyword == "type"){
                m_Image.loadTransitionType();
                TransitionSet = true;
            }
            if(keyword == "file"){
                m_Image.loadTransitionFile();
                TransitionSet = true;
            }
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
                ||  name ==  "custom" ||  name ==  "back" ||   name ==  "transition" || name ==  "help"){
                throw std::invalid_argument("Command " + name + "already exists.");
            }   
            break;
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv)  ){
                throw std::invalid_argument("Exited.");
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
