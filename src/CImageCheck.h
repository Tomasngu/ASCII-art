#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "CImage.h"
#include "CVideo.h"
#include "CFormatBMP.h"
#include "CFormatTGA.h"
#include "CFilterResize.h"

class CImageCheck{
public:
    CImageCheck(const std::string &);
    const std::string checkImage(void) const;
    CImage getImage(void) const;
    CVideo getImagesInDir(void) const;
private:
    const std::string & m_Path;
    static constexpr int optimalSize = 160;
    static constexpr double ASCIIratio = 1.5;
    static std::map<std::string, std::shared_ptr<CFormat>> m_Formats;
    static const std::string getFileExtension(const std::string &);  
    static void makePretty(CImage &);
    static CImage getOneImageDir(const std::string &);
};