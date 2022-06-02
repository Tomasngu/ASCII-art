#pragma once

#include "CImage.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

class CVideo{
public: 
    CVideo() = default;
    void play(void);
    void addFrame(const CImage &);
    const CImage & getFrame(int index);
    void removeFrame(int index);
    void switchframes(int idx1, int idx2);
    size_t getSize(void);

private:
    static int kbhit(void);
    static int getch(void);
    std::vector<CImage> m_Images;
    static constexpr int SPACEBAR = 32;
    static constexpr int END = 'e';
};