#include "Draw.h"
#include <iostream>
#include <iomanip>

void Draw::ClearScreen() {
    system("cls");
}

void Draw::PrintNumAlignCenter(int num, int w) {
    int len = 0, tnum = num;
    while (tnum) {
        tnum /= 10;
        len++;
    }
    if (num == 0)
        len = 1;
    if (w < len) {
        std::cout << "ERROR" << std::endl;
        return;
    }
    w -= len;
    for (int i = 0; i < w - w / 2; i++)
        std::cout << ' ';
    std::cout << num;
    for (int i = 0; i < w / 2; i++)
        std::cout << ' ';
}

void Draw::PrintUi(GameData Data) {
    std::cout << "            HAPPY!     SCORE: ";
    PrintNumAlignCenter(Data.GetScore(), 6);
    std::cout << "     BEST: ";
    PrintNumAlignCenter(Data.GetBestScore(), 6);
    std::cout << "     !HAPPY" << std::endl;
    std::cout << "            ----------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "                       |------|------|------|------|" << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << "                       |";
        for (int j = 0; j < 4; j++) {
            PrintNumAlignCenter(Data.GetPositionNumber(i, j), 6);
            std::cout << ("|");
        }
        std::cout << std::endl;
        std::cout << "                       |------|------|------|------|" << std::endl;
    }

    std::cout << std::endl << std::endl;
    std::cout << "            ----------------------------------------------------" << std::endl;
    if(!Data.IsGameOver())
        std::cout << "              [W]:UP  [S]:DOWN  [A]:LEFT  [D]:RIGHT  [Q]:EXIT" << std::endl;
    else
        std::cout << "                Do you want to play the game again?([Y]/[N])" << std::endl;                   " << std::endl
}

Draw::Draw() = default;
