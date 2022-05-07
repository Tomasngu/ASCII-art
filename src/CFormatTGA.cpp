#include "CFormatTGA.h"

CImage CFormatTGA::loadFile(const std::string & fileName ) const{
    CImage image;
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if(!ifs.good()) throw std::invalid_argument("Invalid file.");
    Header header;
    ifs.read(reinterpret_cast<char *>(&header), sizeof(header));
    // image.m_Width =  (header.Width[1] << 8) + header.Width[0];
    // image.m_Height = (header.Height[1] << 8) + header.Height[0];
    std::cout << (int)header.imageType << std:: endl;
    std::cout << (int ) header.bitsPerPixel << std:: endl;
    // assert(header.depth == 24 && "Image depth should be 24bits");
    
    if(header.bitsPerPixel != 24){
        throw std::invalid_argument("Format not supported");
    }
    //TODO compressed image
    /*
    for(size_t i = 0; i < image.m_Height; i++){
        ifs.read(reinterpret_cast<char *>(image.m_Pixels[i].data()), image.m_Width*header.bitsPerPixel/8);
    }
    */
    return image;

}
