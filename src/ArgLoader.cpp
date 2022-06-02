#include"ArgLoader.h"

std::vector<int> ArgLoader::getNums(int count){
    std::stringstream ss = getStream();
    std::vector<int> nums;
    char c;
    for(int i = 0; i < count; i++){
        int a;
        if(!(ss >> a)) throw std::invalid_argument("Incorrect input.");
        nums.push_back(a);
    }
    if(ss >> c) throw std::invalid_argument("Incorrect input.");
    return nums;
}        
const std::string ArgLoader::getString(void){
    std::stringstream ss = getStream();
    std::string ret;
    ss >> ret;
    std::string error;
    if(ss >> error) throw std::invalid_argument("Too many inputs.");
    return ret;
}
const std::string ArgLoader::getLine(void){
    std::string line;
    std::getline(std::cin, line);
    checkEOF();
    if(line.empty()) throw std::invalid_argument("Empty input.");
    return line;
}

std::stringstream ArgLoader::getStream(void){
    std::string line;
    getline(std::cin, line);  
    checkEOF();             
    std::stringstream ss(line);
    if(ss.str().empty()) throw std::invalid_argument("Empty input.");
    return ss;
}
void ArgLoader::checkEOF(void){
    if(std::cin.eof()) {
        throw std::invalid_argument("CTRL + D.");
    }   
}
void ArgLoader::clear(void){
    if(std::cin.peek() == '\n'){
        std::cin.clear();
        std::cout << "Peeking and clearing" << std::endl;
        std::cin.ignore();
    }
}