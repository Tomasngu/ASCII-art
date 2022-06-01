#include"CVideoHandler.h"

CVideoHandler::CVideoHandler(CVideo & video)
:m_Video(video)
{}

void CVideoHandler::start(void) {
    showHelp();
    while(true){
        std::cout << std::endl << "Command: "; 
        std::string command;
        std::cin >> command;
        if(std::cin.eof()) {
            throw std::invalid_argument("Exited.");
        }
        if(command == "exit"){
            throw std::invalid_argument("Exited.");
        }
        else if(command == "play"){
            m_Video.play();
        }
        else if(command == "help"){
            // m_Image.render();
            showHelp();    
        }
        else{
            std:: cout << "Command " + command + " not found." << std::endl; 
        }
    }
}

void CVideoHandler::showHelp(void) const {
    std::cout << 
    R"(List of avalaible commands: 
        play        -   plays animation.  
        help        -   prints this help menu. 
        exit        -   exits the program. )"
    << std::endl;
}