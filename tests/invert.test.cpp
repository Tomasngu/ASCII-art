#include <iostream>
#include <cassert>
#include "../src/CFilterInverse.h"
#include "../src/CFilterMirror.h"
#include "../src/CFilterFlip.h"

bool SameImage(const CImage & first, const CImage & second){
    if(first.m_Height != second.m_Height || first.m_Width != second.m_Width) return false;
    for(int h = 0; h < first.m_Height; ++h){
        for(int w = 0; w < first.m_Width; ++w){
            if(first.m_Pixels[h][w] != second.m_Pixels[h][w]){
                return false;
            }
        }
    }
    return true;
}
void fill(CImage & image){
    for(int h = 0; h < image.m_Height; ++h){
        for(int w = 0; w < image.m_Width; ++w){
            image.m_Pixels[h][w] = h + w;
        }
    }
}

void apply(CImage & image){
    for(int i = 0; i < 2; i++){
        static CFilterInverse invert;
        invert.edit(image);
    }
}
void apply2(CImage & image){
    for(int i = 0; i < 5000; i++){
        static CFilterMirror mirror;
        static CFilterInverse invert;
        mirror.edit(image);
        invert.edit(image);
    }
}
void apply3(CImage & image){

    static CFilterFlip flip;
    static CFilterInverse invert;
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image); 
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    flip.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    invert.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
    invert.edit(image);
    flip.edit(image);
}

int main(void){
    CImage first(100, 50);
    fill(first);
    CImage second = first;
    apply(second);
    assert(SameImage(first, second));
    apply2(second);
    assert(SameImage(first, second));
    apply3(second);
    assert(SameImage(first, second));

    CImage third(100, 100);
    fill(third);
    CImage fourth = third;
    apply(fourth);
    assert(SameImage(third, fourth));
    apply2(fourth);
    assert(SameImage(third, fourth));
    apply3(fourth);
    assert(SameImage(third, fourth));

}