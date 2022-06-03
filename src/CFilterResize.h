#pragma once
/**
 * @file CFilterResize.h
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CFilter.h"
#include<cmath>
/**
 * @brief Class for resizing the image.
 * Using bilinear interpolation. 
 * 
 */
class CFilterResize : public CFilter{
public:
    /**
     * @brief Construct a new CFilterResize object.
     * 
     * @param scale overal scale of image.
     */
    explicit CFilterResize(double scale);
    /**
     * @brief Construct a new CFilterResize object.
     * 
     * @param scaleH height scaling.
     * @param scaleW width scaling.
     */
    explicit CFilterResize(double scaleH, double scaleW);
    /**
     * @brief Resizes given image.
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
    std::uint8_t calculatePixel(const CImage &, double, double) const;
    /**
     * @brief Constant which sets how much should height of the image scale.
     * 
     */
    double m_ScaleH;
    /**
     * @brief Constant which sets how much should width of the image scale.
     * 
     */
    double m_ScaleW;
};