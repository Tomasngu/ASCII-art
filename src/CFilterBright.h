#pragma once

#include "CFilter.h"

class CFilterBright : public CFilter{
public:
    virtual void edit(CImage &) const override;
    virtual std::unique_ptr<CFilter> clone() const override;
private:
    static constexpr int diff = 28;
};