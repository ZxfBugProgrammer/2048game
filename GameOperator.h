#ifndef INC_2048GAME_GAMEOPERATOR_H
#define INC_2048GAME_GAMEOPERATOR_H

#include "GameData.h"

class GameOperator {
public:
    GameOperator();

    void WaitMove();

private:
    int getch();
};


#endif //INC_2048GAME_GAMEOPERATOR_H
