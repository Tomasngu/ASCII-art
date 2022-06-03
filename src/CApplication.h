#pragma once

/**
 * @file CApplication.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 */

#include<iostream>
#include<map>
#include<memory>
#include "CFileLoader.h"
#include "CImageHandler.h"
#include "CVideoHandler.h"
#include "ArgLoader.h"
#include "messages.h"
/**
 * @brief class for the whole application.
 * 
 */
class CApplication{
public:
    CApplication() = default;
    CApplication (const CApplication &) = delete;
    CApplication & operator =(const CApplication &) = delete;
    /**
     * @brief Running application.
     * 
     */
    void Run(void) const;
private:
    /**
     * @brief Clears terminal and prints pretty menu.
     * 
     */
    void printMenu(void) const;
};