#pragma once

#include "CFilter.h"

class CFilterInverse : public CFilter{
    virtual void edit(CImage &) const override;
    
};