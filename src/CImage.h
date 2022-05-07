#pragma once

#include<vector>
#include<iostream>
#include<map>

class CImage{
public:
    CImage(void) = default;
    CImage( std::uint16_t height, std::uint16_t width);
    void printmySize(void);
    void Render() const;
    std::vector<std::vector<std::uint8_t>> m_Pixels;

private:
    std::uint16_t m_Height;
    std::uint16_t m_Width;
    static std::map<int, char> numtoAscii;
};