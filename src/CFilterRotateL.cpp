/**
 * @file CFilterRotateL.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 */

#include "CFilterRotateL.h"

void CFilterRotateL::edit(CImage & origimage) const {
    
    CImage image = CFilterRotate::getTransposed(origimage);

    for(int w = 0 ; w < image.m_Width; ++w){
        for(int h = 0; h < image.m_Height/2; ++h){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[image.m_Height - 1 - h][w]);
        }
    }
    CFilterRotate::ScaledRotation(image);
    origimage = image;
}
std::unique_ptr<CFilter> CFilterRotateL::clone() const{
    return std::make_unique<CFilterRotateL> (*this);
}