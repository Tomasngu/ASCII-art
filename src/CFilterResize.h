#pragma once

#include "CFilter.h"
#include<cmath>

class CFilterResize : public CFilter{
public:
    CFilterResize(double scale);
    CFilterResize(double scaleH, double scaleW);
    virtual void edit(CImage &) const override;
private:
    std::uint8_t calculatePixel(const CImage &, double, double) const;
    double m_ScaleH;
    double m_ScaleW;
};