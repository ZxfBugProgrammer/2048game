/*
 * This class control all the game
 */

#include "Control.h"

Control::Control() {
}

void Control::loop(GameData Data, Draw DrawUi, GameOperator Operator) {
    while (true) {
        DrawUi.PrintUi(Data);
        int Tempop = Operator.GetMoveNumber();
        if (Tempop == QUIT) {
            std::cout << "                Do you really want to quite the game?([Y]/[N])" << std::endl;
            Tempop = Operator.GetMoveNumber();
            if (Tempop == YES)
                break;
        }
        if(Tempop != NO && Tempop != YES && Tempop != QUIT)
        {
            Operator.Move(Data, Tempop);
            GameData.MakeNewNumber();
        }
        DrawUi.ClearScreen();
    }
}

void Control::begin() {
    Draw DrawUi;
    GameData Data;
    GameOperator Operator;
    loop(Data, DrawUi, Operator);
}