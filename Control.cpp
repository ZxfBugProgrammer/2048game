/*
 * This class control all the game
 */

#include "Control.h"
#include "Draw.h"
#include <iostream>

Control::Control() {

}

void Control::begin() {
    Draw interface;
    interface.PrintUi();
}