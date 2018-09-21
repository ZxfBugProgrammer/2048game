#include "GameOperator.h"
#include <iostream>

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else

#include <termios.h>
#include <unistd.h>

#endif

GameOperator::GameOperator() {
}

bool GameOperator::WaitMove() {
    int ch = getkey();
}

int GameOperator::getkey() {
#ifdef _WIN32
    return getch();
#else
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
#endif
}

int GameOperator::GetMoveNumber() {
    return this->statusNum;
}

void GameOperator::Move() {

}

