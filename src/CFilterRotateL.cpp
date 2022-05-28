#include "CFilterRotateL.h"

void CFilterRotateL::edit(CImage & origimage) const {
    
    CImage image = CFilterRotate::getTransposed(origimage);

    for(int w = 0 ; w < image.m_Width; ++w){
        for(int h = 0; h < image.m_Height/2; ++h){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[image.m_Height - 1 - h][w]);
        }
    }    
    origimage = image;
}