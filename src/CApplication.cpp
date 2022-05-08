#include "CApplication.h"


void CApplication::Run(void){
    printMenu();
    std::cout << "Enter path to file or directory: ";
    std::string path;
    std::cin >> path;
    std::cout << "\x1B[2J\x1B[H"; //Clear terminal
    CImageCheck check;
    std::string type = check.checkImage(path);
    if(type == "file"){
        if(m_Formats.find(check.getFileExtension(path)) == m_Formats.end()) throw std::invalid_argument(path + " has invalid extension");
        CImage image = m_Formats[check.getFileExtension(path)]->loadFile(path); //Polymorphism
        image.Render();
    }
    else{
        //TODO
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

std::map<std::string, std::shared_ptr<CFormat>> CApplication::m_Formats = {{"bmp", std::make_shared<CFormatBMP>(CFormatBMP())},
                                                                       {"tga", std::make_shared<CFormatTGA>(CFormatTGA())} };