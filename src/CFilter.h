#pragma once

#include "CImage.h"

class CFilter{
public:
    virtual void edit(CImage &) const = 0;    
    virtual ~CFilter() = default;
    virtual std::unique_ptr<CFilter> clone() const = 0;
};