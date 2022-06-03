#pragma once
/**
 * @file CFilterRotateR.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CFilterRotate.h"

/**
 * @brief Class for rotating the image to the right.
 * 
 */
class CFilterRotateR: public CFilterRotate{
public:
    /**
     * @brief Rotates the image to the right.
     * 
     */
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
};