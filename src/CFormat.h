#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include<string>
#include<iomanip>
#include<stdexcept>
#include"CImage.h"

class CFormat{
public:
    virtual CImage loadFile(const std::string &) const = 0;
protected:
    struct Pixel{
        std::uint8_t R, G, B;
    };
};

