#include "CImage.h"

CImage::CImage( std::uint16_t height,  std::uint16_t width):
    m_Height(height), m_Width(width)
{
    m_Pixels.resize(height, std::vector<std::uint8_t>(width));
}

void CImage::printmySize(void){
    std::cout << "Height, Width = " << m_Height << " " << m_Width << std::endl; 
}

void CImage::Render() const{
    for(size_t h = 0; h < m_Pixels.size(); h++){
        for(size_t w = 0; w < m_Pixels[0].size(); w++){
            std::cout << numtoAscii[m_Pixels[h][w]/28 ];
        }
        std::cout << std::endl;
    }
}
std::map<int, char>  CImage::numtoAscii = {{0,' '}, {1, '.' }, {2, '*' }, {3, ':' },
    {4, 'o' }, {5, '&' },{6, '8' }, {7, '#' },{8, '@' } };