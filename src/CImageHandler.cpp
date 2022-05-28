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
            static CFilterRotateR rotR;
            rotR.edit(m_Image);
            m_Image.render();
        }
        else if(command == "rotateL"){
            static CFilterRotateL rotL;
            rotL.edit(m_Image);
            m_Image.render();
        }
        else if(command == "mirror"){
            static CFilterMirror mir;
            mir.edit(m_Image);
            m_Image.render();
        }
        else if(command == "flip"){
            static CFilterFlip flip;
            flip.edit(m_Image);
            m_Image.render();
        }
        else if(command == "bright"){
            static CFilterBright bright;
            bright.edit(m_Image);
            m_Image.render();
        }
        else if(command == "dark"){
            static CFilterDark dark;
            dark.edit(m_Image);
            m_Image.render();
        }
        else if(command == "invert"){
            static CFilterInverse inv;
            inv.edit(m_Image);
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
        flip    -   flips the image upside down.
        invert  -   inverts grayscale colors.
        bright  -   makes image brighter
        dark    -   makes image darker.
        resize  -   changes size of image.
        
        new     -   sets new image.  
        help    -   prints this help menu. 
        exit    -   exits the program. )"
    << std::endl;

}