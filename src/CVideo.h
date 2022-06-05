#pragma once
/**
 * @file CVideo.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CImage.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
/**
 * @brief Class of Video.
 * 
 */
class CVideo{
public: 
    /**
     * @brief Construct a new CVideo object.
     * 
     */
    CVideo() = default;
    /**
     * @brief play animation.
     * 
     */
    void play(void);
    /**
     * @brief Add one frame to video.
     * 
     */
    void addFrame(const CImage &);
    /**
     * @brief Get given frame from video.
     * 
     * @param index of frame.
     * @return const CImage& frame.
     */
    const CImage & getFrame(int index);
    /**
     * @brief Remove given frame from video.
     * 
     * @param index of removed frame.
     */
    void removeFrame(int index);
    /**
     * @brief Switch two given frames in video.
     * 
     * @param idx1 first frame
     * @param idx2 second frame
     */
    void switchframes(int idx1, int idx2);
    /**
     * @brief Get the length of video in frames.
     * 
     * @return size_t length of video.
     */
    size_t getSize(void) const;

private:
    /**
     * @brief Checking if keyboard has been hit.
     * @source https://itecnote.com/tecnote/r-c-non-blocking-keyboard-input/
     * @return int != 0 if hit.
     */
    static bool kbhit(void);
    /**
     * @brief Getting character without blocking
     * @source http://www.cplusplus.com/forum/unices/18395/
     * @return int loaded ASCII char.
     */
    static int getch(void);
    /**
     * @brief Given Frames.
     * 
     */
    std::vector<CImage> m_Images;
    static constexpr int SPACEBAR = 32;
    static constexpr int END = 'e';
    /**
     * @brief Coefficient for usleep converting to centiseconds.
     * 
     */
    static constexpr int sleepCenti = 10000;
    /**
     * @brief Sleep coefficient in centiseconds.
     * 
     */
    static constexpr int sleepIn = 50;
};