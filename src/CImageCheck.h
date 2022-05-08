#pragma once
#include <string>
#include <filesystem>
#include <vector>

class CImageCheck{
public:
    CImageCheck() = default;
    const std::string checkImage(const std::string & ) const;
    std::vector<std::string> getImagesInDir(const std::string &) const ;
    const std::string getFileExtension(const std::string &) const;
};