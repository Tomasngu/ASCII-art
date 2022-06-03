/**
 * @file ArgLoader.cpp 
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include"ArgLoader.h"
#include"messages.h"

std::vector<int> ArgLoader::getNums(int count){
    std::stringstream ss = getStream();
    std::vector<int> nums;
    char c;
    for(int i = 0; i < count; i++){
        int a;
        if(!(ss >> a)) throw std::invalid_argument(ERR_INCORRECT);
        nums.push_back(a);
    }
    if(ss >> c) throw std::invalid_argument(ERR_MANY);
    return nums;
}        
const std::string ArgLoader::getString(void){
    std::stringstream ss = getStream();
    std::string ret;
    ss >> ret;
    std::string error;
    if(ss >> error) throw std::invalid_argument(ERR_MANY);
    return ret;
}
const std::string ArgLoader::getLine(void){
    std::string line;
    std::getline(std::cin, line);
    checkEOF();
    if(line.empty()) throw std::invalid_argument(ERR_EMPTY);
    return line;
}

std::stringstream ArgLoader::getStream(void){
    std::string line;
    getline(std::cin, line);  
    checkEOF();             
    std::stringstream ss(line);
    if(ss.str().empty()) throw std::invalid_argument(ERR_EMPTY);
    return ss;
}
void ArgLoader::checkEOF(void){
    if(std::cin.eof()) {
        throw std::invalid_argument(EXITED);
    }   
}