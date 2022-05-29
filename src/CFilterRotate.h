#pragma once

#include "CFilter.h"
#include "CFilterResize.h"

class CFilterRotate : public CFilter{
public:
    CFilterRotate() = default;
    virtual ~CFilterRotate() = default;
protected:
    CImage getTransposed(CImage &) const;
    void ScaledRotation(CImage &) const;
    static constexpr double rotationScale = 0.5;
};