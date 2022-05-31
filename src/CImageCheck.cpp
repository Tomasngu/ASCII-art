#include "CImageCheck.h"

CImageCheck::CImageCheck(const std::string & path)
:m_Path(path)
{}


const std::string CImageCheck::checkImage(void) const{
    const std::filesystem::path p = m_Path;
    if(!std::filesystem::exists(p)) throw std::invalid_argument("Path to " + m_Path + " does not exist or " + m_Path + " does not exist.");
    if(std::filesystem::is_regular_file(p)) return "file";
    if(std::filesystem::is_directory(p)) return "directory";
    throw std::invalid_argument(m_Path + " is not directory nor a file.");
    return "BAD";
}
CImage CImageCheck::getImage(void) const{
    if(m_Formats.find(getFileExtension(m_Path)) == m_Formats.end())  throw std::invalid_argument(m_Path + " has invalid extension");
    CImage image = m_Formats[getFileExtension(m_Path)]->loadFile(m_Path); //Polymorphism
    makePretty(image);
    return image;
}
void CImageCheck::makePretty(CImage & image) {
    CFilterResize rescale(1, ASCIIratio);
    rescale.edit(image);
    int max = (image.m_Height > image.m_Width) ? image.m_Height : image.m_Width;
    if(optimalSize > max) return;
    double ratio = (double) optimalSize/max;
    CFilterResize resize(ratio);
    resize.edit(image);
    
}

std::vector<std::string> CImageCheck::getImagesInDir(void) const{
    const std::filesystem::path p = m_Path;
    std::vector<std::string> files;
    for(auto const & entry : std::filesystem::directory_iterator(p)){
        if(entry.is_regular_file()) files.push_back(entry.path().string());
    }
    return files;
}

const std::string CImageCheck::getFileExtension(const std::string & m_Path){
    std::string::size_type index = m_Path.rfind(".");
    if(index != std::string::npos){
        return m_Path.substr(index+1);
    }
    return "";

}

std::map<std::string, std::shared_ptr<CFormat>> CImageCheck::m_Formats = {{"bmp", std::make_shared<CFormatBMP>(CFormatBMP())},
                                                                       {"tga", std::make_shared<CFormatTGA>(CFormatTGA())} };