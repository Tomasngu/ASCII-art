#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<memory>
#include<string>
#include<stdexcept>

using namespace std;

struct Header {
    std::uint8_t idBlockLength;   ///< length of optional id block (placed after header)
    std::uint8_t colorMapType;    ///< color map type; map is placed after id block; 0 = none
    std::uint8_t imageType;       ///< image type/compression; 2 = true color, 10 = RLE compressed true color
    std::uint8_t colorMapSpec[5]; ///< color map specification; not used in our program

    std::uint16_t originX;        ///< horizontal origin of image; most probably 0
    std::uint16_t originY;        ///< vertical origin of image; most probably 0

    std::uint16_t width;          ///< image width
    std::uint16_t height;         ///< image height

    std::uint8_t depth;           ///< bits per pixel; we will use 24 bits (3 bytes)
    std::uint8_t imageDescriptor; ///< image flags; we will not use them
    };

int main(void){
    string fileName = "vagneros.tga";
    std::ifstream ifs(fileName, std::ios::in | std::ios::binary);
    if(!ifs.good()) throw std::invalid_argument("Invalid picture");
    cout << "Funguje" << endl;
    Header header;
    ifs.read(reinterpret_cast<char *>(&header), sizeof(header));
    std::cout << header.imageType << std:: endl;
    if(header.depth != 24) cout << "CHci se zabit" << endl;
    std::cout <<  (int) header.depth << std:: endl;
    int s;  
    std::cout << header.width << std::endl;
}