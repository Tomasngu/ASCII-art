#include "CFileLoader.h"

CFileLoader::CFileLoader(const std::string & path)
:m_Path(path)
{}


const std::string CFileLoader::checkImage(void) const{
    const std::filesystem::path p = m_Path;
    if(!std::filesystem::exists(p)) throw std::invalid_argument("Path to " + m_Path + " does not exist or " + m_Path + " does not exist.");
    if(std::filesystem::is_regular_file(p)) return "file";
    if(std::filesystem::is_directory(p)) return "directory";
    throw std::invalid_argument(m_Path + " is not directory nor a file.");
    return "BAD";
}
CImage CFileLoader::getImage(void) const{
    if(m_Formats.find(getFileExtension(m_Path)) == m_Formats.end())  throw std::invalid_argument(m_Path + " has invalid extension");
    CImage image = m_Formats[getFileExtension(m_Path)]->loadFile(m_Path); //Polymorphism
    makePretty(image);
    return image;
}
void CFileLoader::makePretty(CImage & image) {
    CFilterResize rescale(1, ASCIIratio);
    rescale.edit(image);
    int max = (image.m_Height > image.m_Width) ? image.m_Height : image.m_Width;
    if(optimalSize > max) return;
    double ratio = (double) optimalSize/max;
    CFilterResize resize(ratio);
    resize.edit(image);
}

CVideo CFileLoader::getImagesInDir(void) const{
    const std::filesystem::path p = m_Path;
    if(std::filesystem::is_empty(p)) throw std::invalid_argument("Empty directory");
    CVideo video;
    for(auto const & entry : std::filesystem::directory_iterator(p)){
        if(!entry.is_regular_file()) throw std::invalid_argument(entry.path().string() + " is not a file.");
        CImage image = getOneImageDir(entry.path().string());
        video.addFrame(image);
    }
    return video;
}

CImage CFileLoader::getOneImageDir(const std::string & path){
    if(m_Formats.find(getFileExtension(path)) == m_Formats.end())  throw std::invalid_argument(path + " has invalid extension.");
    CImage image = m_Formats[getFileExtension(path)]->loadFile(path); //Polymorphism
    makePretty(image);
    return image;
}

const std::string CFileLoader::getFileExtension(const std::string & m_Path){
    std::string::size_type index = m_Path.rfind(".");
    if(index != std::string::npos){
        return m_Path.substr(index+1);
    }
    return "";

}

std::map<std::string, std::shared_ptr<CFormat>> CFileLoader::m_Formats = {{"bmp", std::make_shared<CFormatBMP>(CFormatBMP())},
                                                                       {"tga", std::make_shared<CFormatTGA>(CFormatTGA())} };