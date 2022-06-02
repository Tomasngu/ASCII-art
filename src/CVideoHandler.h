#pragma once
#include "CVideo.h"
#include "CImageCheck.h"
#include "ArgLoader.h"

class CVideoHandler{
public:
    CVideoHandler() = default;
    CVideoHandler(CVideo &);
    void start(void);
private:
    void showHelp(void) const;
    CVideo & m_Video;
    int lastShownframe = 0;
};