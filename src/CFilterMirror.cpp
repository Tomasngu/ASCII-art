/**
 * @file CFilterMirror.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilterMirror.h"

void CFilterMirror::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width/2; ++w){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[h][image.m_Width - 1 - w]);
        }
    }
}
std::unique_ptr<CFilter> CFilterMirror::clone() const{
    return std::make_unique<CFilterMirror> (*this);
}