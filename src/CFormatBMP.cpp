#include "CFormatBMP.h"


CImage CFormatBMP::loadFile(const std::string & fileName ) const{
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    HeaderDIP headerDip;
    validFormat(ifs, fileName, headerDip);
    CImage image(headerDip.Height, headerDip.Width);
    bool upsideDown = true;
    std::uint32_t padding = 4 - (headerDip.Width*3) % 4;
    for(std::uint32_t h = 0 ; h < headerDip.Height; ++h){
        for(std::uint32_t w = 0; w < headerDip.Width; ++w){
            CFormat::Pixel pix;
            ifs.read(reinterpret_cast<char *>(&pix), sizeof(pix));
            if(upsideDown){
                image.m_Pixels[headerDip.Height - h -1][w] = CFormat::getGrayscale(pix);
            }
            else{
                image.m_Pixels[h][w] = CFormat::getGrayscale(pix);
            }
        }
        //Throw away padding
        for(std::uint32_t i = 0; i < padding; ++i){
            std::uint8_t rest;
            ifs.read(reinterpret_cast<char *>(&rest), sizeof(rest));
        }
    }    
    return image;
}

bool CFormatBMP::validFormat(std::ifstream & ifs, const std::string & fileName, HeaderDIP & headerDip) const{
    if(!ifs.good()) throw std::invalid_argument("Failed to read file " + fileName);
    HeaderBMP header;
    ifs.read(reinterpret_cast<char *>(&header.name), 2);
    ifs.read(reinterpret_cast<char *>(&header.size), 12);
    if(header.name[0] != 'B' || header.name[1] != 'M')throw std::invalid_argument(fileName + " should be type BM.");
    
    ifs.read(reinterpret_cast<char *>(&headerDip), sizeof(headerDip));
    if(!ifs.good()) throw std::invalid_argument("Reading failed after header " + fileName);
    if(headerDip.bitsPerPixel != 24) throw std::invalid_argument("Each pixel of + "  + fileName + " should have 24 bits.");
    if(headerDip.compression != 0) throw std::invalid_argument(fileName + " should not be compressed.");
    if(headerDip.headersize != 124) throw std::invalid_argument(fileName + " should have 124 header size");
    std::uint32_t rowSize = ((headerDip.Width *headerDip.bitsPerPixel+31)/32)*4;
    if(rowSize*headerDip.Height + headerDip.headersize + 14 != header.size) throw(fileName + " does not have valid size");
    return true;
}