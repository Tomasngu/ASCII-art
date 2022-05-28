#include"CFilterBright.h"

void CFilterBright::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            if(image.m_Pixels[h][w] + 28 >= 255){
                image.m_Pixels[h][w] = 255;
            }
            else{
                image.m_Pixels[h][w]+=28;
            }
        }
    }
}