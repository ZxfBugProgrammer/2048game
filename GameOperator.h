#ifndef INC_2048GAME_GAMEOPERATOR_H
#define INC_2048GAME_GAMEOPERATOR_H

#include "GameData.h"

class GameOperator {
public:
    GameOperator();

    void Test();

    //wait player press key
    //if player press unaccepted key return false
    bool WaitMove();

    //return player pressed key number
    int GetMoveNumber();

    void Move(GameData &data, int ope);

private:
    int getkey();

    int statusNum;
};


#endif //INC_2048GAME_GAMEOPERATOR_H
