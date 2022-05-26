#pragma once

#include "CFilter.h"

class CFilterRotate : public CFilter{
public:
    virtual void edit(CImage &) const override;
};