#pragma once

#include "CImage.h"

class CFilter{
public:
    virtual void edit(CImage &) const = 0;    
};