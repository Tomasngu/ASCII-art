#include"CFilterInverse.h"

void CFilterInverse::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            image.m_Pixels[h][w] = 255 - image.m_Pixels[h][w];
        }
    }
}