#include "CFilterResize.h"

CFilterResize::CFilterResize(double scale)
:m_ScaleH(scale), m_ScaleW(scale)
{}
CFilterResize::CFilterResize(double scaleH, double scaleW)
:m_ScaleH(scaleH), m_ScaleW(scaleW)
{}

void CFilterResize::edit(CImage & origimage) const {
    const double H_scale = m_ScaleH;
    const double W_scale = m_ScaleW;
    CImage image(origimage.m_Height * H_scale, origimage.m_Width * W_scale);
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            double origH = h/H_scale; 
            double origW = w/W_scale;
            std::uint8_t q = calculatePixel(origimage, origH, origW);
            image.m_Pixels[h][w] = q;
        }
    }
    origimage = image;
}

std::uint8_t CFilterResize::calculatePixel(const CImage & origimage, double origH, double origW) const{
    int floorH = std::floor(origH);
    int ceilH = (std::ceil(origH) < origimage.m_Height - 1) ? std::ceil(origH) : origimage.m_Height -1;
    int floorW = std::floor(origW);
    int ceilW = (std::ceil(origW) < origimage.m_Width - 1) ? std::ceil(origW) : origimage.m_Width -1;
    if(floorH == ceilH  && floorW == ceilW){
        return origimage.m_Pixels[floorH][floorW];
    }
    else if(floorH == ceilH){
        std::uint8_t v1 = origimage.m_Pixels[floorH][floorW];
        std::uint8_t v2 = origimage.m_Pixels[floorH][ceilW];
        std::uint8_t v = v1 * (ceilW - origW) + v2 * (origW - floorW);
        return v;
    }
    else if(floorW == ceilW){
        std::uint8_t v1 = origimage.m_Pixels[floorH][floorW];
        std::uint8_t v2 = origimage.m_Pixels[ceilH][floorW];
        std::uint8_t v = v1 * (ceilH - origH) + v2 * (origH - floorH);
        return v;
    }
    else{
        std::uint8_t v1 = origimage.m_Pixels[floorH][floorW];
        std::uint8_t v2 = origimage.m_Pixels[floorH][ceilW];
        std::uint8_t q1 = v1 * (ceilW - origW) + v2 * (origW - floorW);
        std::uint8_t v3 = origimage.m_Pixels[ceilH][floorW];
        std::uint8_t v4 = origimage.m_Pixels[ceilH][ceilW];
        std::uint8_t q2 = v3 * (ceilW - origW) + v4 * (origW - floorW);
        std::uint8_t q = q1 * (ceilH - origH) + q2 *(origH - floorH);
        return q;
    }
}
