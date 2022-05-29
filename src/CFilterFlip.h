#pragma once

#include "CFilter.h"

class CFilterFlip : public CFilter{
public:
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
};