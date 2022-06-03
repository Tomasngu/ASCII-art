/**
 * @file CFilterInverse.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include"CFilterInverse.h"

void CFilterInverse::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            image.m_Pixels[h][w] = RGBsize - image.m_Pixels[h][w];
        }
    }
}
std::unique_ptr<CFilter> CFilterInverse::clone() const{
    return std::make_unique<CFilterInverse> (*this);
}
