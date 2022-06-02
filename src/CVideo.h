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
    CImage & getFrame(int index);
    void removeFrame(const CImage & image, int index);
    void switchframes(int idx1, int idx2);

private:
    static int kbhit(void);
    static int getch(void);
    std::vector<CImage> m_Images;
};