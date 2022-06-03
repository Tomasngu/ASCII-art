#pragma once

/**
 * @file ArgLoader.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "messages.h"

/**
 * @brief class with static methods to handle I/O.
 * 
 */
class ArgLoader{
public:
    /**
     * @brief Get integers from user.
     * @param count number of wanted integers.
     * @return std::vector<int> vector of loaded integers.
     */
    static std::vector<int> getNums(int count);
    /**
     * @brief Get string from user.
     * 
     * @return const std::string loaded string
     */
    static const std::string getString(void);
    /**
     * @brief Get the whole line from user (including spaces)
     * 
     * @return const std::string loaded line.
     */
    static const std::string getLine(void);
private:
    /**
     * @brief Helper method to load stream using getline
     * 
     * @return std::stringstream loaded stream.
     */
    static std::stringstream getStream(void);
    /**
     * @brief Checking EOF.
     * 
     */
    static void checkEOF(void);
};