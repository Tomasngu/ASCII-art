#include "CFormatTGA.h"
#include "CFormat.h"

int main(void){
    CFormatTGA f;
    CImage image =  f.loadFile("vagner.tga");
    image.Render();
    return 0;
}