#pragma once

#include "CImage.h"

class CFilter{
    virtual void edit(CImage &) const;    
};