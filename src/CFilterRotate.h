#pragma once

#include "CFilter.h"

class CFilterRotate : public CFilter{
    virtual void edit(CImage &) const override;
};