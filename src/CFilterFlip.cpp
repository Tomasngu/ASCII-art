/**
 * @file CFilterFlip.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilterFlip.h"

void CFilterFlip::edit(CImage & image) const {
    for(int h = 0, h1 = image.m_Height -1; h < h1; ++h, --h1){
        for(int w = 0; w < image.m_Width; ++w){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[h1][w]);
        }
    }
}
std::unique_ptr<CFilter> CFilterFlip::clone() const{
    return std::make_unique<CFilterFlip> (*this);
}