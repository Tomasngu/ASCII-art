#include "CFormat.h"

std::uint8_t CFormat::getGrayscale(CFormat::Pixel pix){
    return (red* pix.R + green *pix.G + blue*pix.B);
}