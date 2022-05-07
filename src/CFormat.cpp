#include "CFormat.h"

std::uint8_t CFormat::getGrayscale(CFormat::Pixel pix){
    return (0.3* pix.R + 0.6 *pix.G + 0.1 *pix.B);
}