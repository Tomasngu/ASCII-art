#pragma once

#include "CFilter.h"

class CFilterBright : public CFilter{
public:
    virtual void edit(CImage &) const override;
};