/*
 * This class control all the game
 */

#include "Control.h"

Control::Control() = default;

void Control::loop(GameData Data, Draw DrawUi, GameOperator Operator) {
    bool flagQuit = false;
    bool flagGameOver = false;
    Data.InitNewGame();
    while (true) {
        DrawUi.PrintUi(Data, flagQuit, flagGameOver);

        int Tempop;
        if (flagGameOver) {
            Tempop = Operator.GetMoveNumber();
            while (Tempop != YES && Tempop != NO)
                Tempop = Operator.GetMoveNumber();
            if (Tempop == YES) {
                Data.InitNewGame();
                flagGameOver = false;
            } else
                break;
        }

        else if (flagQuit) {
            Tempop = Operator.GetMoveNumber();
            while (Tempop != YES && Tempop != NO)
                Tempop = Operator.GetMoveNumber();
            if (Tempop == YES)
                break;
            else
                flagQuit = false;
        }

        else
        {
            Tempop = Operator.GetMoveNumber();

            if (Tempop == QUIT)
                flagQuit = true;

            if (Tempop != NO && Tempop != YES && Tempop != QUIT) {
                Operator.Move(Data, Tempop);
                if (Data.IsGameOver())
                    flagGameOver = true;
                if(Data.IsMove)
                    Data.MakeNewNumber();
            }
        }

        DrawUi.ClearScreen();
    }
}

void Control::begin() {
    Draw DrawUi;
    GameData Data;
    GameOperator Operator;
    srand((unsigned) time(NULL));
    loop(Data, DrawUi, Operator);
}