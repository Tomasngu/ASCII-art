/**
 * @file CVideo.cpp
 * @author Huu Quy Nguyen (nguyehu7@fit.cvut.cz)
 * @date 2022-06-03
 * 
 */

#include "CVideo.h"

void CVideo::addFrame(const CImage & image){
    m_Images.push_back(std::move(image));
}
const CImage & CVideo::getFrame(int index){
    if((size_t) index >= m_Images.size() || index < 0 ) throw std::invalid_argument(ERR_RANGE);
    return m_Images[index];
}

void CVideo::switchframes(int idx1, int idx2){
    if((size_t) idx1 >= m_Images.size() || idx1 < 0 ) throw std::invalid_argument(ERR_RANGE);
    if((size_t) idx2 >= m_Images.size() || idx2 < 0 ) throw std::invalid_argument(ERR_RANGE );
    std::swap(m_Images[idx1], m_Images[idx2]);
}
void CVideo::removeFrame(int index){
    if((size_t) index >= m_Images.size() || index < 0 ) throw std::invalid_argument(ERR_RANGE );
    m_Images.erase(m_Images.begin() + index);
}
size_t CVideo::getSize(void) const{
    return m_Images.size();
}

void CVideo::play(void) {
    size_t count = 0;
    while(true){
        while (!kbhit()) {
            if(count >= m_Images.size()) return;
            m_Images[count++].render();
            std::cout << "Pause     - spacebar" << std::endl;
            std::cout << "End       - e" << std::endl;
            usleep(sleepCenti*sleepIn);
        }
        char x = getch();
        if(x == END) return;
        if(x != SPACEBAR) continue;
        while (!kbhit() && getch() != SPACEBAR) {
            usleep(sleepCenti);
        }
    }
}
bool CVideo::kbhit(void){
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

int CVideo::getch(void)
{
  int ch;
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  ch = getchar(); /* standard getchar call */
  if(ch == EOF) throw std::invalid_argument("GRRR");
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
  return ch; /*return received char */
}
