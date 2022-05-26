#include "CFormat.h"

std::uint8_t CFormat::getGrayscale(CFormat::Pixel pix){
    return (0.2989* pix.R + 0.5870 *pix.G + 0.1140*pix.B);
}