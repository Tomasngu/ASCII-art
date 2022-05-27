#pragma once
#include "CFilterRotate.h"

class CFilterRotateL: public CFilterRotate{
public:
    virtual void edit(CImage &) const override;
};