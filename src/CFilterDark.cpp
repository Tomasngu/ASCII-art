#include"CFilterDark.h"

void CFilterDark::edit(CImage & image) const {
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            if(image.m_Pixels[h][w] - 28 <= 0){
                image.m_Pixels[h][w] = 0;
            }
            else{
                image.m_Pixels[h][w]-= 28;
            }
        }
    }
}
std::unique_ptr<CFilter> CFilterDark::clone() const{
    return std::make_unique<CFilterDark> (*this);
}