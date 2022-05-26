#pragma once

#include<vector>
#include<iostream>
#include<string>
#include<map>

class CImage{
public:
    CImage(void) = default;
    CImage( std::uint16_t height, std::uint16_t width);
    void printmySize(void);
    void render(void) const;
    void rescale(void);
    std::vector<std::vector<std::uint8_t>> m_Pixels;
    std::uint16_t m_Height;
    std::uint16_t m_Width;

private:
    static std::map<int, char> numtoAscii;
    static std::map<int, char> numtoAscii2;
    static std::string ANSIClear;
};