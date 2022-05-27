#pragma once

#include "CFilter.h"

class CFilterRotate : public CFilter{
public:
    CFilterRotate() = default;
    virtual ~CFilterRotate() = default;
protected:
    CImage getTransposed(CImage &) const;
};