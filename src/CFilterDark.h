#pragma once

#include "CFilter.h"

class CFilterDark : public CFilter{
public:
    virtual void edit(CImage &) const override;
};