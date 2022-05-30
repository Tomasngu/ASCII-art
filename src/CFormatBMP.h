#pragma once
#include "CFormat.h"

class CFormatBMP : public CFormat{
public:
    virtual CImage loadFile(const std::string & ) const override;
private:
    struct HeaderBMP{
        std::uint8_t name[2];
        std::uint32_t size;
        std::uint32_t garbage;
        std::uint32_t offset;
    };
    struct HeaderDIP{
        std::uint32_t headersize;
        std::uint32_t Width;
        std::uint32_t Height;
        std::uint16_t plane;
        std::uint16_t bitsPerPixel;
        std::uint32_t compression;
        std::uint32_t pixelSize;
        std::uint32_t garbage[25]; //100 bits
    };
    bool validFormat(std::ifstream &, const std::string &, HeaderDIP &) const;

};