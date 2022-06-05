#pragma once

/**
 * @file CFileLoader.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include <string>
#include <filesystem>
#include <vector>
#include <set>
#include "CImage.h"
#include "CVideo.h"
#include "CFormatBMP.h"
#include "CFormatTGA.h"
#include "CFilterResize.h"
/**
 * @brief class loading image file or directory.
 * 
 */
class CFileLoader{
public:
    /**
     * @brief Construct a new CFileLoader object with file/directory name.
     * 
     */
    CFileLoader(const std::string &);
    /**
     * @brief Determines basic properties about given file name.
     * 
     * @return const std::string 
     */
    const std::string checkImage(void) const;
    /**
     * @brief Get Image from given file.
     * 
     * @return CImage 
     */
    CImage getImage(void) const;
    /**
     * @brief Get Video (list of images) from file.
     * 
     * @return CVideo 
     */
    CVideo getImagesInDir(void) const;
private:
    /**
     * @brief given path to file/dir.
     * 
     */
    const std::string m_Path;
    /**
     * @brief chosen constant of good height of image in Pixels.
     * 
     */
    static constexpr int optimalSize = 160;
    /**
     * @brief ratio of ASCII char height to width.
     * 
     */
    static constexpr double ASCIIratio = 1.5;
    /**
     * @brief map of pointers to classes of different image formats.
     * 
     */
    static std::map<std::string, std::shared_ptr<CFormat>> m_Formats;
    /**
     * @brief Get the File Extension from file.
     * 
     * @return const std::string file extension
     */
    static const std::string getFileExtension(const std::string &);  
    /**
     * @brief Resizes and rescales loaded image.
     * 
     */
    static void makePretty(CImage &);
    /**
     * @brief Get one image from directory.
     * 
     * @return CImage loaded image.
     */
    static CImage getOneImageDir(const std::string &);
};