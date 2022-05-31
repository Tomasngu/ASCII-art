#include "CImage.h"

CImage::CImage( std::uint16_t height,  std::uint16_t width):
    m_Height(height), m_Width(width)
{
    m_Pixels.resize(height, std::vector<std::uint8_t>(width));
}

void CImage::printmySize(void){
    std::cout << "Height, Width = " << m_Height << " " << m_Width << std::endl; 
}

void CImage::render(void) {
    std::cout << ANSIClear;
    for(int h = 0; h < m_Height; h++){
        for(int w = 0; w < m_Width; w++){
            if(!m_CustomSet) {
                std::cout << numtoAscii[m_Pixels[h][w]/30];
            }
            else{
                std::cout << m_CustomTransition[m_Pixels[h][w]/(255/m_CustomTransition.size())];
            }
        }
        std::cout << std::endl;
    }
    // std::cout << ANSIClear;
}
void CImage::rescale(void){
    for(int h = 0 ; h < m_Height/3; ++h){
        for(int w = 0; w < m_Width/2; ++w){
            std::uint16_t sum = (std::uint16_t) m_Pixels[3*h][2*w] + (std::uint16_t) m_Pixels[3*h][2*w + 1];
            sum += (std::uint16_t) m_Pixels[3*h + 1][2*w] + (std::uint16_t) m_Pixels[3*h + 1][2*w + 1]; 
            sum += (std::uint16_t) m_Pixels[3*h + 2][2*w] + (std::uint16_t) m_Pixels[3*h + 2][2*w + 1];
            m_Pixels[h][w] = (std::uint8_t) (sum/6);
        }
    }
    m_Height /= 3;
    m_Width /= 2;
}

void CImage::printNum(void) const{
    std::cout << ANSIClear;
    for(int h = 0; h < m_Height; h++){
        for(int w = 0; w < m_Width; w++){
            std::cout << (int) m_Pixels[h][w] << " ";
        }
        std::cout << std::endl;
    }
}
void CImage::loadTransitionFile(void){
    std::cout << "Enter path to file with your custom transition." << std::endl;
    std::cout << "Transition should start with least dense characters first to the most dense at the end. File should have only one line." << std::endl;
    std::string path;
    std::cin >> path;
    if(std::cin.eof()) throw std::invalid_argument("CTRL + D."); 
    const std::filesystem::path p = path;
    if(!std::filesystem::exists(p)) throw std::invalid_argument("Path to " + path + " does not exist or " + path + " does not exist.");
    if(!std::filesystem::is_regular_file(p)) throw std::invalid_argument(path + " is not a file.");
    std::ifstream ifs(path);
    if(!ifs.good()) throw std::invalid_argument("Failed to read file " + path);
    std::string line;
    int count = 0;
    int chars = 0;
    while(std::getline(ifs, line)){
        if(line.empty()) continue;
        for(char c: line){
            m_CustomTransition[chars++] = c;
        }
        count++;
    }
    if(count > 1)  throw std::invalid_argument(path + " has multiple lines.");
    if(!ifs.eof()) throw std::invalid_argument("Reading failed.");
    if(chars == 0) throw std::invalid_argument("No characters given."); 
    m_CustomSet = true;
    return;
}

void CImage::loadTransitionType(void){
    std::cout << "Type ASCII characters of your preffered transition." << std::endl;
    std::cout << "Transition should start with least dense characters first to the most dense at the end." << std::endl;
    std::string line;
    std::getline(std::cin, line);
    if(std::cin.eof()) throw std::invalid_argument("CTRL + D."); 
    int chars = 0;
    for(char c: line){
        m_CustomTransition[chars++] = c;
    }
    if(chars == 0) throw std::invalid_argument("No characters given."); 
    m_CustomSet = true;
    return;
}


std::map<int, char>  CImage::numtoAscii = {{0,' '}, {1, '.' }, {2, '*' }, {3, ':' },
    {4, 'o' }, {5, '&' },{6, '8' }, {7, '#' },{8, '@' } };

std::map<int, char>  CImage::numtoAscii2 = {{0,'.'}, {1,'\''}, {2,'`'}, {3,'^'}, {4,'"'}, {5,','}, {6,':'}, {7,';'}, {8,'I'}, {9,'l'},
 {10,'!'}, {11,'i'}, {12,'>'}, {13,'<'}, {14,'~'}, {15,'+'}, {16,'_'}, {17,'-'}, {18,'?'}, {19,']'}, {20,'['}, {21,'}'}, {22,'{'}, {23,'1'}, 
 {24,')'}, {25,'('}, {26,'|'}, {27,'\\'}, {28,'/'}, {29,'t'}, {30,'f'}, {31,'j'}, {32,'r'}, {33,'x'}, {34,'n'}, {35,'u'}, {36,'v'}, {37,'c'},
  {38,'z'}, {39,'X'}, {40,'Y'}, {41,'U'}, {42,'J'}, {43,'C'}, {44,'L'}, {45,'Q'}, {46,'0'}, {47,'O'}, {48,'Z'}, {49,'m'}, {50,'w'}, {51,'q'},
   {52,'p'}, {53,'d'}, {54,'b'}, {55,'k'}, {56,'h'}, {57,'a'}, {58,'o'}, {59,'*'}, {60,'#'}, {61,'M'}, {62,'W'}, {63,'&'}, {64,'8'}, {65,'%'}, {66,'B'}, {67,'@'}, {68,'$'}};
