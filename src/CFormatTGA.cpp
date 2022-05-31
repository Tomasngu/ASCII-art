#include "CFormatTGA.h"

CImage CFormatTGA::loadFile(const std::string & fileName ) const{
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    HeaderTGA header;
    validFormat(ifs, fileName, header);
    std::uint16_t Width =  header.Width;
    std::uint16_t Height = header.Height;
    CImage image(Height, Width);
    // image.printmySize();
    // std::cout << (int)header.imageType << std:: endl;
    // std::cout << (int)header.bitsPerPixel << std:: endl;
    
    bool upsideDown = ! (bool) (header.Alpha & (1 << 5) );
    //TODO compressed image
    //std::cout << header.bitsPerPixel/8 << std::endl;
    // int cnt = 0;
    //std::cout << image.m_Pixels.size() << std::endl;
    // std::cout << image.m_Pixels[0].size() << std::endl;
    for(int h = 0 ; h < Height; ++h){
        for(int w = 0; w < Width; ++w){
            CFormat::Pixel pix;
            ifs.read(reinterpret_cast<char *>(&pix), sizeof(pix));
            if(!ifs.good()) throw std::invalid_argument("Failed to read file " + fileName);
            if(upsideDown){
                image.m_Pixels[Height - h -1][w] = CFormat::getGrayscale(pix);
            }
            else{
                image.m_Pixels[h][w] = CFormat::getGrayscale(pix);
            }
        }
    }
    char error;
    ifs.read(reinterpret_cast<char *>(&error), sizeof(error));
    if(!ifs.eof()) throw std::invalid_argument(fileName + " does not have valid size");
    return image;
}

bool CFormatTGA::validFormat(std::ifstream & ifs, const std::string & fileName, HeaderTGA & header)const{
    if(!ifs.good()) throw std::invalid_argument("Failed to read file " + fileName);
    ifs.read(reinterpret_cast<char *>(&header), sizeof(header));
    if(!ifs.good()) throw std::invalid_argument("Reading failed after header " + fileName);
    if(header.ID_length != (std::uint8_t) 0x0) throw std::invalid_argument(fileName + " should have 0 ID Length.");
    if(header.colorMapType != (std::uint8_t) 0x0) throw std::invalid_argument(fileName + " should have no color map type.");
    if(header.imageType != (std::uint8_t) 0x2) throw std::invalid_argument(fileName + " should have image type 2.");
    if(header.bitsPerPixel != 24) throw std::invalid_argument("Each pixel of + "  + fileName + " should have 24 bits.");
    ifs.seekg(0, std::ios::end);
    unsigned int length = ifs.tellg();
    if(header.Height * header.Width * 3 + sizeof(header) != length) throw std::invalid_argument(fileName + " does not have valid size");
    ifs.seekg(sizeof(header), std::ios::beg);
    return true;
}
