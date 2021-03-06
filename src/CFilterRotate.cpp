/**
 * @file CFilterRotate.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilterRotate.h"

CImage CFilterRotate::getTransposed(CImage & origimage)const{
    CImage image(origimage.m_Width, origimage.m_Height);
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            std::swap(image.m_Pixels[h][w], origimage.m_Pixels[w][h]);
        }
    }
    return image;
}
void CFilterRotate::ScaledRotation(CImage & image) const{
    if(!image.isSideWays){
        CFilterResize res(CFilterRotate::rotationScale, 1/CFilterRotate::rotationScale);
        res.edit(image);    
        image.isSideWays = true;
    }else{
        CFilterResize res(CFilterRotate::rotationScale, 1/CFilterRotate::rotationScale);
        res.edit(image);   
        image.isSideWays = false; 
    }
}