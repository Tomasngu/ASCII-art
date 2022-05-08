#include "CFormatBMP.h"
#include "CFormatTGA.h"
#include "CFormat.h"
#include "CApplication.h"

int main(void){
    try{
        CApplication app;
        app.Run();
    }catch ( const std::invalid_argument & e ){
        std::cout << e.what() << std::endl;
    }
}