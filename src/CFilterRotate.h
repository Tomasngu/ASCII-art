#pragma once

/**
 * @file CFilterRotate.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilter.h"
#include "CFilterResize.h"
/**
 * @brief Abstract Class for rotating the image.
 * 
 */
class CFilterRotate : public CFilter{
public:
    /**
     * @brief Destroy the CFilterRotate object
     * 
     */
    virtual ~CFilterRotate() = default;
protected:
    /**
     * @brief Get transposed image.
     * 
     * @return CImage transposed image.
     */
    CImage getTransposed(CImage &) const;
    /**
     * @brief Rescales the image to look pretty.
     * 
     */
    void ScaledRotation(CImage &) const;
    /**
     * @brief Constant of resizing proven by experience.
     * 
     */
    static constexpr double rotationScale = 0.5;
};