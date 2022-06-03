#pragma once
/**
 * @file CFormatTGA.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include<cassert>
#include "CFormat.h"
/**
 * @brief Class for loading TGA image format.
 * 
 */
class CFormatTGA : public CFormat{
public:
    /**
     * @brief Loading image of TGA format.
     * 
     * @param fileName Path to file.
     * @return CImage 
     */
    virtual CImage loadFile(const std::string & fileName) const override;
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
    /**
     * @brief Check if given file is valid TGA format.
     * 
     * @param ifs Stream with loaded pixels.
     * @param fileName Name of file.
     * @param header Header.
     * @return true if valid.
     * @return false otherwise.
     */
    bool validFormat(std::ifstream & ifs, const std::string & fileName, HeaderTGA & header) const;

};