#pragma once

#include "CFilter.h"
#include<cmath>

class CFilterUpsize : public CFilter{
public:
    CFilterUpsize(double scale);
    CFilterUpsize(double scaleH, double scaleW);
    virtual void edit(CImage &) const override;
private:
    std::uint8_t calculatePixel(const CImage &, double, double) const;
    double m_ScaleH;
    double m_ScaleW;
};