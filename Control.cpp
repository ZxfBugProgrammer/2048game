/*
 * This class control all the game
 */

#include "Control.h"


Control::Control() = default;

void Control::loop(GameData Data,Draw DrawUi,GameOperator Operator) {
    while(true)
    {
        DrawUi.PrintUi(Data);
        int Tempop = Operator.GetMoveNumber();
        if(Tempop == QUIT)
        {
            std::cout << "                Do you really want to quite the game?([Y]/[N])" << std::endl;
            if(Operator.GetMoveNumber() == YES)
                break;
            else
                Tempop = Operator.GetMoveNumber();
        }
        Operator.Move(&Data,Tempop);
        DrawUi.ClearScreen();
    }
}

void Control::begin() {
    Draw DrawUi;
    GameData Data;
    GameOperator Operator;
    loop(Data,DrawUi,Operator);
}