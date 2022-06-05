#include "../src/CFormatTGA.h"

using namespace std;

int main(void){
    CFormatTGA tga;
    try{
        tga.loadFile("tests/TGA/empty.tga");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/TGA/empty.tga has invalid header"sv);
    }
    
    try{
        tga.loadFile("tests/TGA/ID.tga");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/TGA/ID.tga should have 0 ID Length."sv);
        // cout << e.what() << endl;
    }
    try{
        tga.loadFile("tests/TGA/color.tga");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/TGA/color.tga should have image type 2."sv);
        // cout << e.what() << endl;
    }
    try{
        tga.loadFile("tests/TGA/bits.tga");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "Each pixel of tests/TGA/bits.tga should have 24 bits."sv);
        // cout << e.what() << endl;
    }
    try{
        tga.loadFile("tests/TGA/bad.tga");
    }
    catch ( const std::invalid_argument & e ){
        assert(e . what () ==  "tests/TGA/bad.tga does not have valid size"sv);
    }

    
}