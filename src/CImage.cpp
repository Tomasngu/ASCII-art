/**
 * @file CImage.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CImage.h"

CImage::CImage( std::uint16_t height,  std::uint16_t width):
    m_Height(height), m_Width(width)
{
    m_Pixels.resize(height, std::vector<std::int16_t>(width));
}


void CImage::render(void) const{
    std::cout << ANSI_CLEAR;
    for(int h = 0; h < m_Height; h++){
        for(int w = 0; w < m_Width; w++){
            printASCII(h, w);
        }
        std::cout << std::endl;
    }
}
void CImage::printASCII(int h, int w) const{
    if(!m_CustomSet) {
        if(m_Pixels[h][w] < 0) {
            std::cout << numtoAscii[0];
        }else if(m_Pixels[h][w] > RGBsize){
            std::cout << numtoAscii[numtoAscii.size()-1];
        }
        else{
            assert( (size_t) m_Pixels[h][w]/(RGBsize/numtoAscii.size() + 1 ) < numtoAscii.size());
            std::cout << numtoAscii[m_Pixels[h][w]/(RGBsize/numtoAscii.size() + 1 )];
        }
    }
    else{
        if(m_Pixels[h][w] < 0) {
            std::cout << m_CustomTransition[0];
        }else if(m_Pixels[h][w] > RGBsize){
            std::cout << m_CustomTransition[m_CustomTransition.size()-1];
        }
        else{
            assert( (size_t) m_Pixels[h][w]/(RGBsize/m_CustomTransition.size() + 1 ) <  m_CustomTransition.size());
            std::cout << m_CustomTransition[m_Pixels[h][w]/(RGBsize/m_CustomTransition.size() + 1 )];
        }
    }
}



void CImage::loadTransitionFile(void){
    std::cout << "Enter path to file with your custom transition." << std::endl;
    std::cout << "Transition should start with least dense characters first to the most dense at the end. File should have only one line." << std::endl;
    std::string path = ArgLoader::getString();
    const std::filesystem::path p = path;
    if(!std::filesystem::exists(p)) throw std::invalid_argument("Path to " + path + " does not exist or " + path + " does not exist.");
    if(!std::filesystem::is_regular_file(p)) throw std::invalid_argument(path + " is not a file.");
    std::ifstream ifs(path);
    if(!ifs.good()) throw std::invalid_argument("Failed to read file " + path);
    std::string line;
    int count = 0;
    std::set<char> chars;
    while(std::getline(ifs, line)){
        if(line.empty()) continue;
        for(char c: line){
            if(chars.find(c) != chars.end()){
                throw std::invalid_argument("Repeating characters.");
            }
            else{
                chars.insert(c);
            }
        }
        count++;
    }
    if(count > 1)  throw std::invalid_argument(path + " has multiple lines.");
    if(!ifs.eof()) throw std::invalid_argument("Reading failed.");
    if(chars.empty()) throw std::invalid_argument("Empty file.");
    std::vector<char> custom(chars.begin(), chars.end());
    m_CustomTransition = custom;
    m_CustomSet = true;
    return;
}

void CImage::loadTransitionType(void){
    std::cout << "Type ASCII characters of your preffered transition." << std::endl;
    std::cout << "Transition should start with least dense characters first to the most dense at the end." << std::endl;
    std::string line = ArgLoader::getLine();
    std::set<char> chars;
    for(char c: line){
        if(chars.find(c) != chars.end()){
                throw std::invalid_argument("Repeating characters.");
        }
        else{
            chars.insert(c);
        }
    }
    m_CustomSet = true;
    std::vector<char> custom(chars.begin(), chars.end());
    m_CustomTransition = custom;
    return;
}

const std::vector<char> CImage::numtoAscii = {' ', '.', '*',  ':' ,  'o' , '&' , '8' ,  '#' , '@' };

