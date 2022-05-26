#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "CImage.h"
#include "CFormatBMP.h"
#include "CFormatTGA.h"

class CImageCheck{
public:
    CImageCheck(const std::string &);
    const std::string checkImage(void) const;
    CImage getImage(void) const;
    std::vector<std::string> getImagesInDir(void) const ;
    static const std::string getFileExtension(const std::string &);
private:
    const std::string & m_Path;
    static std::map<std::string, std::shared_ptr<CFormat>> m_Formats;
};