#pragma once

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





class CImageHandler{
public:
    CImageHandler() = default;
    CImageHandler(CImage & image);
    void start(void);
private:
    void showHelp(void) const;
    void printCustoms(void) const;
    void loadTransition(void) const;
    void loadTransitionWord(const std::string &) const;
    void createCustom(void);
    const std::string loadName(void) const;
    CImage & m_Image;
    static std::map<std::string, std::shared_ptr<CFilter>> Commands;
    std::map<std::string, std::vector<std::pair<std::string,std::unique_ptr<CFilter>>>> m_CustomCommands;
    bool m_CustomSet = false;
};

