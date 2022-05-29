#pragma once
#include "CFilterRotate.h"

class CFilterRotateR: public CFilterRotate{
public:
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
};