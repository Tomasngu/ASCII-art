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
#include "CImageCheck.h"





class CImageHandler{
public:
    CImageHandler() = default;
    CImageHandler(CImage & image);
    void start(void);
private:
    void showHelp(void);
    void printCustoms(void);
    void newImage(void);
    void loadTransition(void);
    void loadTransitionWord(const std::string &);
    void createCustom(void);
    const std::string loadName(void);
    CImage & m_Image;
    static std::map<std::string, std::shared_ptr<CFilter>> Commands;
    std::map<std::string, std::vector<std::pair<std::string,std::unique_ptr<CFilter>>>> m_CustomCommands;
    bool m_CustomSet = false;
};

