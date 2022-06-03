/**
 * @file main.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @brief Main file for ASCII art app.
 * @date 2022-06-03 
 * 
 * 
 */


#include "CFormatBMP.h"
#include "CFormatTGA.h"
#include "CFormat.h"
#include "CApplication.h"
/**
 * @brief Main function to run Application
 * 
 * @return int 0 on success, 1 otherwise.
 */
int main(void){
    try{
        CApplication app;
        app.Run();
        return 0;
    }catch ( const std::invalid_argument & e ){
        std::cout << '\n' << e.what() << std::endl;
        return 1;
    }
}