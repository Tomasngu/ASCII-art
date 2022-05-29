#pragma once

#include<vector>
#include<iostream>
#include<string>
#include <filesystem>
#include<fstream>
#include<map>
#include<memory>

class CImage{
public:
    CImage(void) = default;
    CImage(std::uint16_t height, std::uint16_t width);
    void printmySize(void);
    void render(void);
    void rescale(void);
    void printNum(void) const;
    void loadTransitionFile(void);
    void loadTransitionType(void);
    std::vector<std::vector<std::uint8_t>> m_Pixels;
    std::uint16_t m_Height;
    std::uint16_t m_Width;

private:
    static std::map<int, char> numtoAscii;
    static std::map<int, char> numtoAscii2;
    std::map<int, char> m_CustomTransition;
    bool m_CustomSet = false;
    static constexpr std::string_view ANSIClear = "\x1B[2J\x1B[H";
};