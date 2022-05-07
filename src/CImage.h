#pragma once

#include<vector>
#include<iostream>

struct CImage{
public:
    void Render() const;
    size_t m_Height;
    size_t m_Width;
    std::vector<std::vector<uint8_t>> m_Pixels;
};