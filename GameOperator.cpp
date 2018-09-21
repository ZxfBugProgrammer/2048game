#include "GameOperator.h"
#include <iostream>
#include <stdio.h>
#include "OperatorDef.h"

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
    if (ch == 'w' || ch == KEY_UP) {
        statusNum = UP;
        return true;
    }
    if (ch == 's' || ch == KEY_DOWN) {
        statusNum = DOWN;
        return true;
    }
    if (ch == 'a' || ch == KEY_LEFT) {
        statusNum = LEFT;
        return true;
    }
    if (ch == 'd' || ch == KEY_RIGHT) {
        statusNum = RIGHT;
        return true;
    }
    if (ch == 'q') {
        statusNum = QUIT;
        return true;
    }
    if (ch == 'y') {
        statusNum = YES;
        return true;
    }
    if (ch == 'n' || ch == 'N') {
        statusNum = NO;
        return true;
    }
    return false;
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
    while (!WaitMove());
    return this->statusNum;
}

void GameOperator::Test() {
    std::cout << GetMoveNumber();
}

void GameOperator::Move(GameData &data, int ope) {

}

