/*
 * This class control all the game
 */

#include "Control.h"

Control::Control() {
}

void Control::loop(GameData Data, Draw DrawUi, GameOperator Operator) {
    bool flagQuit = false;
    bool flagGameOver = false;
    while (true) {
        DrawUi.PrintUi(Data,flagQuit,flagGameOver);
        flagQuit = false;
        int Tempop = Operator.GetMoveNumber();
        if (Tempop == QUIT) {
            Tempop = Operator.GetMoveNumber();
            flagQuit = true;
            if (Tempop == YES)
                break;
        }
        if(Tempop != NO && Tempop != YES && Tempop != QUIT)
        {
            Operator.Move(Data, Tempop);
            Data.MakeNewNumber();
        }
        if(Data.IsGameOver())
            flagGameOver = true;
        DrawUi.ClearScreen();
    }
}

void Control::begin() {
    Draw DrawUi;
    GameData Data;
    GameOperator Operator;
    loop(Data, DrawUi, Operator);
}