#include "Draw.h"
#include <iostream>
#include <iomanip>
#include <afxres.h>

void Draw::ClearScreen() {
#ifdef _WIN32
    /* 重设光标输出位置清屏可以减少闪烁，system("cls")为备用清屏命令，均为Windows平台相关*/
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
#else
    printf("\033c");     /* linux下的清屏命令 */
    printf("\033[?25l"); /* linux下的隐藏输入光标 */
#endif
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

void Draw::PrintUi(GameData Data,bool flagQuit,bool flagGameOver) {
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
    if (flagGameOver)
        std::cout << "                Do you want to play the game again?([Y]/[N])" << std::endl;
    else if(flagQuit)
        std::cout << "                Do you really want to quite the game?([Y]/[N])" << std::endl;
    else
        std::cout << "              [W]:UP  [S]:DOWN  [A]:LEFT  [D]:RIGHT  [Q]:EXIT" << std::endl;
}

Draw::Draw() = default;
