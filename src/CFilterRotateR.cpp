#include "CFilterRotateR.h"

void CFilterRotateR::edit(CImage & origimage) const {
    
    CImage image = CFilterRotate::getTransposed(origimage);
    
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width/2; ++w){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[h][image.m_Width - 1 - w]);
        }
    }    
    origimage = image;
}