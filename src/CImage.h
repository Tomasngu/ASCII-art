#pragma once
/**
 * @file CImage.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include<vector>
#include<iostream>
#include<string>
#include <filesystem>
#include<fstream>
#include<map>
#include<memory>
#include<climits>
#include<cassert>
#include<set>
#include"ArgLoader.h"
#include"messages.h"
/**
 * @brief Struct of image.
 * 
 */
struct CImage{
public:
    /**
     * @brief Construct a new CImage object.
     * 
     * @param height Height of image.
     * @param width Width of image.
     */
    explicit CImage(std::uint16_t height, std::uint16_t width);
    /**
     * @brief Renders image in terminal.
     * 
     */
    void render(void) const;
    /**
     * @brief Load ASCII transition from file.
     * 
     */
    void loadTransitionFile(void);
    /**
     * @brief Load ASCII transition from keyboard.
     * 
     */
    void loadTransitionType(void);
    /**
     * @brief Pixels of image.
     * 
     */
    std::vector<std::vector<std::int16_t>> m_Pixels;
    /**
     * @brief Height of image in pixels.
     * 
     */
    std::uint16_t m_Height;
    /**
     * @brief Width of image in pixels.
     * 
     */
    std::uint16_t m_Width;
    /**
     * @brief True if image is loaded sideways during rotation.
     * 
     */
    bool isSideWays = false;
private:
    /**
     * @brief ASCII chars conversion.
     * 
     */
    static const std::vector<char> numtoAscii;
    /**
     * @brief Custom ASCII chars transition conversion.
     * 
     */
    std::vector<char> m_CustomTransition;
    /**
     * @brief Prints ASCII character of given coordinates.
     * 
     * @param h Y-coordinate of a pixel.
     * @param w X-coordinate of a pixel.
     */
    void printASCII(int h, int w) const;
    /**
     * @brief True if Custom Transition set.
     * 
     */
    bool m_CustomSet = false;
    /**
     * @brief Range of RGB.
     * 
     */
    static constexpr int RGBsize = 255;
};