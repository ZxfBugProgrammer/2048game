/*
 * This class control all the game
 */

#include "Control.h"
#include "Draw.h"
#include "GameOperator.h"
#include <iostream>

Control::Control() {

}

void Control::begin() {
    Draw interface;
    GameData Data;
    interface.PrintUi(Data);
}