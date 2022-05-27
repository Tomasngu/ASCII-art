#pragma once

#include<iostream>
#include<map>
#include<memory>
#include "CImageCheck.h"
#include "CImageHandler.h"


class CApplication{
public:
    CApplication() = default;
    CApplication (const CApplication &) = delete;
    CApplication & operator =(const CApplication &) = delete;
    void Run(void);
private:
    void printMenu(void);
    static std::map<std::string, std::shared_ptr<CFormat>> m_Formats;
};