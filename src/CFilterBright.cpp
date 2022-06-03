/**
 * @file CFilterBright.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include"CFilterBright.h"

void CFilterBright::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            if(image.m_Pixels[h][w] + diff >= INT16_MAX){
                image.m_Pixels[h][w] = INT16_MAX;
            }
            else{
                image.m_Pixels[h][w] += diff;
            }
        }
    }
}

std::unique_ptr<CFilter> CFilterBright::clone() const{
    return std::make_unique<CFilterBright> (*this);
}