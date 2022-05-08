#pragma once

#include "CFilter.h"

class CFilterMirror : public CFilter{
    virtual void edit(CImage &) const override;
};