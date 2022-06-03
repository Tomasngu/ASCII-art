#pragma once
/**
 * @file CVideoHandler.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CVideo.h"
#include "CFileLoader.h"
#include "ArgLoader.h"

/**
 * @brief Class to handle animation commands.
 * 
 */
class CVideoHandler{
public:
    /**
     * @brief Construct a new CVideoHandler object
     * 
     * @param video given video
     */
    explicit CVideoHandler(CVideo & video);
    /**
     * @brief Start menu with commands.
     * 
     */
    void start(void);
private:
    /**
     * @brief Prints help menu on terminal.
     * 
     */
    void showHelp(void) const;
    /**
     * @brief Add one frame to video.
     * 
     */
    void addFrame(void);
    /**
     * @brief Show given frame.
     * 
     */
    void showFrame(void);
    /**
     * @brief Switch two frames from video.
     * 
     */
    void switchFrames(void);
    /**
     * @brief Remove given frame from video.
     * 
     */
    void removeFrame(void);
    /**
     * @brief Print range of allowed indexes for frames.
     * 
     */
    void printAllowedIndexes(void) const;
    /**
     * @brief Video
     * 
     */
    CVideo m_Video;
    /**
     * @brief Frame last shown.
     * 
     */
    int lastShownframe = 0;
};