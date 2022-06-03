#pragma once

/**
 * @file CFilterDark.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilter.h"
/**
 * @brief Filter class for darkness.
 * 
 */
class CFilterDark : public CFilter{
public:
    /**
     * @brief Makes the given image darker.
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
     * @brief Chosen constant for all pixels to apply.
     * 
     */
    static constexpr int diff = 28;
};