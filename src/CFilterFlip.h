#pragma once
/**
 * @file CFilterFlip.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilter.h"
/**
 * @brief Class for flipping the image.
 * 
 */
class CFilterFlip : public CFilter{
public:
    /**
     * @brief Flips the given image upside down.
     * 
     */
    virtual void edit(CImage &) const override;
    /**
     * @brief Get clone of itself.
     * 
     * @return std::unique_ptr<CFilter> clone of itself.
     */
    virtual std::unique_ptr<CFilter> clone() const override;
};