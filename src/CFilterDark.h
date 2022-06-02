#pragma once

#include "CFilter.h"

class CFilterDark : public CFilter{
public:
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
private:
    static constexpr int diff = 28;
};