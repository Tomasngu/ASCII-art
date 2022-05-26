#include "CFilterRotate.h"

void CFilterRotate::edit(CImage & origimage) const {
    
    CImage image(origimage.m_Width, origimage.m_Height);
    //int max = (image.m_Height > image.m_Width) ? image.m_Height : image.m_Width;
    // image.m_Pixels.resize(max, std::vector<std::uint8_t>(max, 100));
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            std::swap(image.m_Pixels[h][w], origimage.m_Pixels[w][h]);
        }
    }
    
    // std::swap(image.m_Height, image.m_Width);
    for(int h = 0 ; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width/2; ++w){
            std::swap(image.m_Pixels[h][w], image.m_Pixels[h][image.m_Width - 1 - w]);
        }
    }    
    origimage = image;
}