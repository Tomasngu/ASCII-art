#pragma once

#include<iostream>
#include<string>
#include"CImage.h"
#include"CFilterRotateL.h"
#include"CFilterRotateR.h"
#include"CFilterFlip.h"
#include"CFilterMirror.h"
#include"CFilterDark.h"
#include"CFilterBright.h"
#include"CFilterInverse.h"

class CImageHandler{
public:
    CImageHandler(CImage & image);
    void start(void);
    void showHelp(void);
private:
    CImage & m_Image;
};

