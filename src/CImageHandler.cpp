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
        std::cout << std::endl << "Command: "; 
        std::string command;
        std::cin >> command;
        if(std::cin.eof()) {
            throw std::invalid_argument("Exited.");
        }
        if(command == "exit"){
            throw std::invalid_argument("Exited.");
        }
        else if(command == "new"){
            newImage();
            m_Image.render();
        }
        else if(command == "help"){
            m_Image.render();
            showHelp();    
        }
        else if(command == "transition"){
            loadTransition();
            m_Image.render();
        }
        else if(Commands.find(command) != Commands.end()){
            Commands[command]->edit(m_Image); //Polymorphism
            m_Image.render();
        }
        else{
            std:: cout << "Command " + command + " not found." << std::endl; 
        }
    }
}
void CImageHandler::newImage(void){
    bool ImageSet = false;
    while(!ImageSet){
        try{
            std::cout << "Enter path to file: ";
            std::string path;
            std::cin >> path;
            if(std::cin.eof()) {
            throw std::invalid_argument("CTRL + D.");
        }
            CImageCheck check(path);
            std::string type = check.checkImage();
            if(type != "file") throw std::invalid_argument(path + " is not a file.");
            CImage image = check.getImage();
            CFilterResize rescale(1, 1.5);
            rescale.edit(image);
            m_Image = image;
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
void CImageHandler::loadTransition(void){
    std::cout << "Choose \"type\" if you want to type the transition yourself" << std::endl;
    std::cout << "Choose \"file\" if you want to load the transition from file" << std::endl;
    std::string command;
    std::cin >> command;
    if(std::cin.eof()) {
        throw std::invalid_argument("Exited.");
    }
    if(command == "type" || command == "file"){
        loadTransitionWord(command);
    }
    else{
        std:: cout << "Command " + command + " not found." << std::endl; 
    }
}

void CImageHandler::loadTransitionWord(const std::string & keyword){
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

void CImageHandler::showHelp(void){
    std::cout << 
    R"(List of avalaible commands: 
        rotateR     -   rotates image 90° to the right.
        rotateL     -   rotates image 90° to the left.
        mirror      -   mirrors the image.
        flip        -   flips the image upside down.
        invert      -   inverts grayscale colors.
        bright      -   makes the image brighter.
        dark        -   makes the image darker.
        upsize      -   makes the image larger.
        downsize    -   makes the image smaller.
        
        new         -   sets new image.  
        help        -   prints this help menu. 
        exit        -   exits the program. )"
    << std::endl;
}
