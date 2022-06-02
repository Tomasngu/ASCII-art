#include"CVideoHandler.h"

CVideoHandler::CVideoHandler(CVideo & video)
:m_Video(video)
{}

void CVideoHandler::start(void) {
    m_Video.getFrame(lastShownframe).render();
    showHelp();
    while(true){
        try{
            std::cout << std::endl << "Command: "; 
            std::string command = ArgLoader::getString();
            if(command == "exit"){
                throw std::invalid_argument("Exited.");
            }
            else if(command == "help"){
                showHelp();    
            }
            else if(command == "play"){
                m_Video.play();
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
        help        -   prints this help menu. 
        exit        -   exits the program. )"
    << std::endl;
}