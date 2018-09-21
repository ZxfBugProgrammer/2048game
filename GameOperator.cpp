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
    if (ch == 'w' || ch == 'W' || ch == 38) {
        statusNum = UP;
        return true;
    }
    if (ch == 's' || ch == 'S' || ch == 40) {
        statusNum = DOWN;
        return true;
    }
    if (ch == 'a' || ch == 'A' || ch == 37) {
        statusNum = LEFT;
        return true;
    }
    if (ch == 'd' || ch == 'D' || ch == 39) {
        statusNum = RIGHT;
        return true;
    }
    if (ch == 'q' || ch == 'Q') {
        statusNum = QUIT;
        return true;
    }
    if (ch == 'y' || ch == 'Y') {
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

