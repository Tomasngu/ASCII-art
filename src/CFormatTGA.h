#pragma once
#include<cassert>
#include "CFormat.h"

class CFormatTGA : public CFormat{
public:
    virtual CImage loadFile(const std::string & ) const override;
private:


    
    struct Header{
        std::uint8_t ID_length[2];
        std::uint8_t imageType;
        std::uint8_t colorSpecs[5];
        std::uint8_t Coords[4];
        std::uint8_t Width[2];
        std::uint8_t Height[2];
        std::uint8_t bitsPerPixel;
        std::uint8_t Alpha;
    };

};