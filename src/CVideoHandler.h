#pragma once
#include "CVideo.h"
#include "CFileLoader.h"
#include "ArgLoader.h"

class CVideoHandler{
public:
    CVideoHandler() = default;
    CVideoHandler(CVideo &);
    void start(void);
private:
    void showHelp(void) const;
    void addFrame(void);
    void showFrame(void) ;
    void switchFrames(void);
    void removeFrame(void);
    void printAllowedIndexes(void) const;
    CVideo & m_Video;
    int lastShownframe = 0;
    static constexpr std::string_view ANSIClear = "\x1B[2J\x1B[H";
};