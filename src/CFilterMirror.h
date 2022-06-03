#pragma once
/**
 * @file CFilterMirror.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */
#include "CFilter.h"
/**
 * @brief Class for mirroring the image.
 * 
 */
class CFilterMirror : public CFilter{
public:
    /**
     * @brief Mirrors given image from left to right.
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