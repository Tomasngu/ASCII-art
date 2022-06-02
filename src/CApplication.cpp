#include "CApplication.h"

void CApplication::Run(void){
    std::cout << "\x1B[2J\x1B[H"; //Clear terminal
    printMenu();
    while(true){
        try{
            std::cout << "Enter path to file or directory: ";
            std::string path = ArgLoader::getString();
            CImageCheck check(path);
            std::string type = check.checkImage();
            if(type == "file"){
                CImage image = check.getImage();
                image.render();
                CImageHandler handler(image);
                handler.start();
            }
            else if (type == "directory") {
                CVideo video = check.getImagesInDir();
                CVideoHandler handler(video);
                handler.start();
                
            }
        }catch ( const std::invalid_argument & e ){
            using namespace std;
            if( e . what () ==  ("CTRL + D."sv) || e . what () ==  ("Exited."sv) ){
                throw std::invalid_argument("Exited.");
            }
            std::cout << e.what() << std::endl;
        }
    }
}

void CApplication::printMenu(void){
    std::cout << "             _____  _____ _____ _____            _____ _______   __  __       _             "      << std::endl;
    std::cout << "      /\\    / ____|/ ____|_   _|_   _|     /\\   |  __ \\__   __| |  \\/  |     | |            "  << std::endl;
    std::cout << "     /  \\  | (___ | |      | |   | |      /  \\  | |__) | | |    | \\  / | __ _| | _____ _ __   " << std::endl;
    std::cout << "    / /\\ \\  \\___ \\| |      | |   | |     / /\\ \\ |  _  /  | |    | |\\/| |/ _` | |/ / _ \\ '__|" << std::endl;
    std::cout << "   / ____ \\ ____) | |____ _| |_ _| |_   / ____ \\| | \\ \\  | |    | |  | | (_| |   <  __/ |   "  << std::endl;
    std::cout << "  /_/    \\_\\_____/ \\_____|_____|_____| /_/    \\_\\_|  \\_\\ |_|    |_|  |_|\\__,_|_|\\_\\___|_|   " << std::endl;     
    std::cout << std::endl;
    std::cout << std::endl;                                                             
}
