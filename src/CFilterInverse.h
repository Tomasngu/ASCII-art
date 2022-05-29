#pragma once

#include "CFilter.h"

class CFilterInverse : public CFilter{
public:
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
};