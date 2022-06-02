#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


class ArgLoader{
public:
    static std::vector<int> getNums(int count);
    static const std::string getString(void);
    static const std::string getLine(void);
    static void clear(void);
private:
    static std::stringstream getStream(void);
    static void checkEOF(void);
};