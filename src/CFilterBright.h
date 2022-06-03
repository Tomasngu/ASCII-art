#pragma once

/**
 * @file CFilterBright.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilter.h"
/**
 * @brief Filter class for brightness.
 * 
 */
class CFilterBright : public CFilter{
public:
    /**
     * @brief Makes the image brighter.
     * 
     */
    virtual void edit(CImage &) const override;
    /**
     * @brief Get clone of itself.
     * 
     * @return std::unique_ptr<CFilter> clone of itself.
     */
    virtual std::unique_ptr<CFilter> clone() const override;
private:
    /**
     * @brief Chosen constant to apply to all pixels.
     * 
     */
    static constexpr int diff = 28;
};