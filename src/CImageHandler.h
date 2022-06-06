#pragma once
/**
 * @file CImageHandler.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include<iostream>
#include<string>
#include<cstring>
#include<memory>
#include<algorithm>
#include"CImage.h"
#include"CFilterRotateL.h"
#include"CFilterRotateR.h"
#include"CFilterFlip.h"
#include"CFilterMirror.h"
#include"CFilterDark.h"
#include"CFilterBright.h"
#include"CFilterInverse.h"
#include "CFilterResize.h"
#include "ArgLoader.h"

/**
 * @brief Class to handle commands for image editing.
 * 
 */
class CImageHandler{
public:
    /**
     * @brief Construct a new CImageHandler object.
     * 
     * @param image Given image.
     */
    explicit CImageHandler(const CImage & image);
    CImageHandler (const CImageHandler &) = delete;
    CImageHandler & operator =(const CImageHandler &) = delete;

    /**
     * @brief Start menu for image editing.
     * 
     */
    void start(void);
private:
    /**
     * @brief Print help menu on terminal.
     * 
     */
    void showHelp(void) const;
    /**
     * @brief Print extended menu for custom commands.
     * 
     */
    void printCustoms(void) const;
    /**
     * @brief Loads custom transition.
     * 
     */
    void loadTransition(void) ;
    /**
     * @brief Loads custom transition depending on keyword.
     * @param keyword Loading file or from keyboard.
     */
    void loadTransitionWord(const std::string & keyword) ;
    /**
     * @brief Create a Custom transition.
     * 
     */
    void createCustom(void);
    /**
     * @brief Loads name of given transition.
     * 
     * @return const std::string loaded name.
     */
    const std::string loadName(void) const;
    /**
     * @brief Image to edit.
     * 
     */
    CImage m_Image;
    /**
     * @brief Commands for editing.
     * 
     */
    static std::map<std::string, std::shared_ptr<CFilter>> Commands;
    /**
     * @brief List of custom made commands.
     * 
     */
    std::map<std::string, std::vector<std::pair<std::string,std::unique_ptr<CFilter>>>> m_CustomCommands;
    /**
     * @brief True if at least one custom command is set.
     * 
     */
    bool m_CustomSet = false;
    /**
     * @brief Coefficient of upsizing.
     * 
     */
    static constexpr double UpScale = 1.2;
    /**
     * @brief Coefficient of downsizing.
     * 
     */
    static constexpr double DownScale = 0.8;

};

