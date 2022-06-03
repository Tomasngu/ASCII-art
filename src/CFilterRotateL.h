#pragma once
/**
 * @file CFilterRotateL.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilterRotate.h"
/**
 * @brief Class for rotating the image to the left.
 * 
 */
class CFilterRotateL: public CFilterRotate{
public:
    /**
     * @brief Rotates the image to the left.
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