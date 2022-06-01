#pragma once
#include "CVideo.h"
#include "CImageCheck.h"

class CVideoHandler{
public:
    CVideoHandler() = default;
    CVideoHandler(CVideo &);
    void start(void);
private:
    void showHelp(void) const;
    CVideo & m_Video;
};