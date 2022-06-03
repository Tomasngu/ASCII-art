#pragma once
/**
 * @file CFilterInverse.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CFilter.h"
/**
 * @brief Class for inverting the image.
 * 
 */
class CFilterInverse : public CFilter{
public:
    /**
     * @brief inverts grayscale of given image.
     * 
     */
    virtual void edit(CImage &) const override;
    /**
     * @brief Get clone of itself.
     * 
     * @return std::unique_ptr<CFilter> clone of itself.
     */
    virtual std::unique_ptr<CFilter> clone() const override;
    /**
     * @brief range of RGB
     * 
     */
    static constexpr int RGBsize = 255;
};