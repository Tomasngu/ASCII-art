#include "CVideo.h"

void CVideo::addFrame(const CImage & image){
    m_Images.push_back(std::move(image));
}
CImage & CVideo::getFrame(int index){
    if((size_t) index >= m_Images.size() || index < 0 ) throw std::invalid_argument("Index out of range.");
    return m_Images[index];
}

void CVideo::switchframes(int idx1, int idx2){
    if((size_t) idx1 >= m_Images.size() || idx1 < 0 ) throw std::invalid_argument("Index out of range.");
    if((size_t) idx2 >= m_Images.size() || idx2 < 0 ) throw std::invalid_argument("Index out of range.");
    std::swap(m_Images[idx1], m_Images[idx2]);
}
void CVideo::play(void) {
    size_t count = 0;
    while(true){
        while (!kbhit()) {
            if(count >= m_Images.size()) return;
            m_Images[count++].render();
            sleep(1);
        }
        char x;
        if((x = getch()) == EOF) throw std::invalid_argument("GRRR");; /* consume the character */
        if(x == 'e') return;
        if(x != 32) continue;
        while (!kbhit() && getch() != 32) {
            sleep(0.1);
        }
    }
}
int CVideo::kbhit(void){
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
        return 1;
    }

    return 0;
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
