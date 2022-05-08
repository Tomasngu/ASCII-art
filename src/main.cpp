#include "CFormatBMP.h"
#include "CFormatTGA.h"
#include "CFormat.h"

int main(void){
    CFormatTGA f;
    CImage image =  f.loadFile("sycinecek.tga");
    image.Render();
    return 0;
}