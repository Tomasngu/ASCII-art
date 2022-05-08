#pragma once
#include<cassert>
#include "CFormat.h"

class CFormatTGA : public CFormat{
public:
    virtual CImage loadFile(const std::string & ) const override;
private:
    struct HeaderTGA{
        std::uint8_t ID_length;
        std::uint8_t colorMapType;
        std::uint8_t imageType;
        std::uint8_t colorSpecs[5];
        std::uint8_t Coords[4];
        std::uint16_t Width;          
        std::uint16_t Height; 
        std::uint8_t bitsPerPixel;
        std::uint8_t Alpha;
    };
    bool validFormat(std::ifstream &, const std::string &, HeaderTGA &) const;

};