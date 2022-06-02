#include"CFilterDark.h"

void CFilterDark::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            if(image.m_Pixels[h][w] - diff <= INT16_MIN){
                image.m_Pixels[h][w] = INT16_MIN;
            }
            else{
                image.m_Pixels[h][w]-= diff;
            }
        }
    }
}
std::unique_ptr<CFilter> CFilterDark::clone() const{
    return std::make_unique<CFilterDark> (*this);
}