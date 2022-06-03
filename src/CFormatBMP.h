#pragma once
/**
 * @file CFormatBMP.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CFormat.h"

/**
 * @brief Class which converts BMP image to CImage class.
 * 
 */
class CFormatBMP : public CFormat{
public:
    /**
     * @brief Loads image with 
     * @param fileName path to file.
     * @return CImage 
     */
    virtual CImage loadFile(const std::string & fileName ) const override;
private:
    /**
     * @brief Header for BMP format.
     * 
     */
    struct HeaderBMP{
        std::uint8_t name[2];
        std::uint32_t size;
        std::uint32_t garbage;
        std::uint32_t offset;
    };
    /**
     * @brief Header dip for BMP format.
     * 
     */
    struct HeaderDIP{
        std::uint32_t headersize;
        std::uint32_t Width;
        std::uint32_t Height;
        std::uint16_t plane;
        std::uint16_t bitsPerPixel;
        std::uint32_t compression;
        std::uint32_t pixelSize;
        std::uint32_t garbage[25]; 
    };
    
    /**
     * @brief Check if given image is valid BMP format.
     * 
     * @param ifs Stream with loaded pixels.
     * @param fileName Name of file.
     * @param headerDip HeaderDip.
     * @return true if valid.
     * @return false otherwise.
     */
    bool validFormat(std::ifstream & ifs, const std::string & fileName, HeaderDIP & headerDip) const;

};