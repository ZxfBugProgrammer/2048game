/*
 * This class will draw a game in a window
 */
#ifndef INC_2048GAME_DRAW_H
#define INC_2048GAME_DRAW_H

#include "GameData.h"

class Draw {
public:
    //initial interface
    Draw();

    void PrintUi(GameData Data);//print the game ui
    void PrintNumAlignCenter(int num,int w);//print a align center num ans total of w space


private:

};


#endif //INC_2048GAME_DRAW_H
