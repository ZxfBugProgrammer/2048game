#ifndef INC_2048GAME_CONTROL_H
#define INC_2048GAME_CONTROL_H


#include "GameData.h"
#include "Draw.h"
#include "GameOperator.h"
#include <iostream>
#include "OperatorDef.h"
#include <time.h>

class Control {
public:
    Control();

    void begin();

    void loop(GameData Data, Draw DrawUi, GameOperator Operator);

};


#endif //INC_2048GAME_CONTROL_H
