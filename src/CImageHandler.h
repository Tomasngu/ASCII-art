#pragma once

#include<iostream>
#include<string>
#include"CImage.h"
#include"CFIlterRotateL.h"
#include"CFIlterRotateR.h"

class CImageHandler{
public:
    CImageHandler(CImage & image);
    void start(void);
    void showHelp(void);
private:
    CImage & m_Image;
};

