#include "../src/CFormatBMP.h"

using namespace std;

int main(void){
    CFormatBMP bmp;
    
    try{
        bmp.loadFile("tests/BMP/empty.bmp");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/BMP/empty.bmp has wrong header."sv);
    }
    
    
    try{
        bmp.loadFile("tests/BMP/bad.bmp");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/BMP/bad.bmp does not have valid size"sv);
    }
    
    try{
        bmp.loadFile("tests/BMP/header.bmp");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/BMP/header.bmp has invalid header size."sv);
    }
    
    try{
        bmp.loadFile("tests/BMP/bits.bmp");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "Each pixel of tests/BMP/bits.bmp should have 24 bits."sv);
    }
    

    
}