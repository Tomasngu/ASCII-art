#pragma once

#include<iostream>
#include<string>
#include<cstring>
#include<memory>
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
    CImageHandler(CImage & image);
    void start(void);
    void showHelp(void);
    void newImage(void);
    void loadTransition(void);
    void loadTransitionWord(const std::string &);

private:
    CImage & m_Image;
    static std::map<std::string, std::shared_ptr<CFilter>> Commands;
};

