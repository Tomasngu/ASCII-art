#include "CFilterMirror.h"

void CFilterMirror::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width/2; ++w){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[h][image.m_Width - 1 - w]);
        }
    }
}