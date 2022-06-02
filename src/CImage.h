#pragma once

#include<vector>
#include<iostream>
#include<string>
#include <filesystem>
#include<fstream>
#include<map>
#include<memory>
#include<climits>
#include<cassert>
#include"ArgLoader.h"

struct CImage{
public:
    CImage(void) = default;
    CImage(std::uint16_t height, std::uint16_t width);
    void render(void) const;
    void rescale(void);
    void printNum(void) const;
    void loadTransitionFile(void);
    void loadTransitionType(void);
    std::vector<std::vector<std::uint8_t>> m_Pixels;
    std::uint16_t m_Height;
    std::uint16_t m_Width;
    bool isSideWays = false;

private:
    static const std::vector<char> numtoAscii;
    static std::map<int, char> numtoAscii2;
    std::vector<char> m_CustomTransition;
    bool m_CustomSet = false;
    static constexpr std::string_view ANSIClear = "\x1B[2J\x1B[H";
};