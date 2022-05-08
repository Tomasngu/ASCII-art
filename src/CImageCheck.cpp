#include "CImageCheck.h"

const std::string CImageCheck::checkImage(const std::string & fileName ) const{
    const std::filesystem::path p = fileName;
    if(!std::filesystem::exists(p)) throw std::invalid_argument("Path to " + fileName + " does not exist or " + fileName + " does not exist.");
    if(std::filesystem::is_regular_file(p)) return "file";
    if(std::filesystem::is_directory(p)) return "directory";
    throw std::invalid_argument(fileName + " is not directory nor a file.");
    return "BAD";
}

std::vector<std::string> CImageCheck::getImagesInDir(const std::string & fileName) const{
    const std::filesystem::path p = fileName;
    std::vector<std::string> files;
    for(auto const & entry : std::filesystem::directory_iterator(p)){
        if(entry.is_regular_file()) files.push_back(entry.path().string());
    }
    return files;
}

const std::string CImageCheck::getFileExtension(const std::string & fileName) const{
    std::string::size_type index = fileName.rfind(".");
    if(index != std::string::npos){
        return fileName.substr(index+1);
    }
    return "";

}

