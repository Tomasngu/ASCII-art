#pragma once

#include<iostream>
#include<map>
#include<memory>
#include "CFileLoader.h"
#include "CImageHandler.h"
#include "CVideoHandler.h"
#include "ArgLoader.h"

class CApplication{
public:
    CApplication() = default;
    CApplication (const CApplication &) = delete;
    CApplication & operator =(const CApplication &) = delete;
    void Run(void) const;
private:
    void printMenu(void) const;
};