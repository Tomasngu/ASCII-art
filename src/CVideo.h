#include "CImage.h"

class CVideo{
public: 
    CVideo() = default;
    void addFrame(const CImage & image);
    void removeFrame(const CImage & image, int index);
};