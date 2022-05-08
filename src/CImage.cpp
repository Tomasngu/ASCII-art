#include "CImage.h"

CImage::CImage( std::uint16_t height,  std::uint16_t width):
    m_Height(height), m_Width(width)
{
    m_Pixels.resize(height, std::vector<std::uint8_t>(width));
}

void CImage::printmySize(void){
    std::cout << "Height, Width = " << m_Height << " " << m_Width << std::endl; 
}

void CImage::Render() const{
    for(size_t h = 0; h < m_Pixels.size(); h++){
        for(size_t w = 0; w < m_Pixels[0].size(); w++){
            std::cout << numtoAscii[m_Pixels[h][w]/28];
        }
        std::cout << std::endl;
    }
}
std::map<int, char>  CImage::numtoAscii = {{0,' '}, {1, '.' }, {2, '*' }, {3, ':' },
    {4, 'o' }, {5, '&' },{6, '8' }, {7, '#' },{8, '@' } };

std::map<int, char>  CImage::numtoAscii2 = {{0,'.'}, {1,'\''}, {2,'`'}, {3,'^'}, {4,'"'}, {5,','}, {6,':'}, {7,';'}, {8,'I'}, {9,'l'},
 {10,'!'}, {11,'i'}, {12,'>'}, {13,'<'}, {14,'~'}, {15,'+'}, {16,'_'}, {17,'-'}, {18,'?'}, {19,']'}, {20,'['}, {21,'}'}, {22,'{'}, {23,'1'}, 
 {24,')'}, {25,'('}, {26,'|'}, {27,'\\'}, {28,'/'}, {29,'t'}, {30,'f'}, {31,'j'}, {32,'r'}, {33,'x'}, {34,'n'}, {35,'u'}, {36,'v'}, {37,'c'},
  {38,'z'}, {39,'X'}, {40,'Y'}, {41,'U'}, {42,'J'}, {43,'C'}, {44,'L'}, {45,'Q'}, {46,'0'}, {47,'O'}, {48,'Z'}, {49,'m'}, {50,'w'}, {51,'q'},
   {52,'p'}, {53,'d'}, {54,'b'}, {55,'k'}, {56,'h'}, {57,'a'}, {58,'o'}, {59,'*'}, {60,'#'}, {61,'M'}, {62,'W'}, {63,'&'}, {64,'8'}, {65,'%'}, {66,'B'}, {67,'@'}, {68,'$'}};