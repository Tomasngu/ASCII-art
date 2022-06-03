#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<string>
#include<iomanip>
#include<stdexcept>
/**
 * @file CFormat.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include"CImage.h"
/**
 * @brief Abstract class of image Format.
 * 
 */
class CFormat{
public:
    /**
     * @brief Pure virtual method to load file.
     * 
     * @return CImage loaded image.
     */
    virtual CImage loadFile(const std::string &) const = 0;
    /**
     * @brief Destroy the CFormat object.
     * 
     */
    virtual ~CFormat() = default;
protected:
    /**
     * @brief Struct of one pixel.
     * 
     */
    struct Pixel{
        std::uint8_t R, G, B;
    };
    /**
     * @brief Converts Pixel to grayscale number.
     * 
     * @param pix 
     * @return std::uint8_t converted number.
     */
    static std::uint8_t getGrayscale(Pixel pix);
    /**
     * @brief Constant for RGB red.
     * 
     */
    static constexpr double red = 0.299;
    /**
     * @brief Constant for RGB green.
     * 
     */
    static constexpr double green = 0.587;
    /**
     * @brief Constant for RGB blue.
     * 
     */
    static constexpr double blue = 0.114;
};

