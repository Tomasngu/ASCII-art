#include "CImageHandler.h"

CImageHandler::CImageHandler(CImage & image):
m_Image(image)
{}

void CImageHandler::start(void){
    showHelp();
    while(true){
        std::cout << std::endl << "Command: "; 
        std::string command;
        std::cin >> command;
        if(command == "exit"){
            throw std::invalid_argument("Exited.");
        }
        else if(command == "new"){

        }
        else if(command == "help"){
            showHelp();
        }
        else if(command == "rotateR"){
            CFilterRotate rot;
            rot.edit(m_Image);
            m_Image.render();
        }
    }
}

void CImageHandler::showHelp(void){
    std::cout << 
    R"(List of avalaible commands: 
        rotateR -   rotates image 90° to the right.
        rotateL -   rotates image 90° to the left.
        mirror  -   mirrors the image.
        invert  -   inverts grayscale colors.
        dark    -   makes image darker.
        bright  -   makes image brighter
        resize  -   changes size of image.
        
        new     -   sets new image  
        help    -   prints this help menu 
        exit    -   exits the program )"
    << std::endl;

}