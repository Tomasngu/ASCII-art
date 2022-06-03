#pragma once
/**
 * @file CFilter.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 */

#include "CImage.h"
/**
 * @brief Abstract class of filter.
 * 
 */
class CFilter{
public:
    /**
     * @brief Pure virtual method which edits given image using polymorphism.
     * 
     */
    virtual void edit(CImage &) const = 0;
    /**
     * @brief Destroy the CFilter object.
     * 
     */
    virtual ~CFilter() = default;
    /**
     * @brief Pure virtual method to clone given class.
     * 
     * @return std::unique_ptr<CFilter> clone of itself
     */
    virtual std::unique_ptr<CFilter> clone() const = 0;
};