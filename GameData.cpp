#include "GameData.h"
#include <iostream>

GameData::GameData() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            num[i][j] = 0;
    score = 0;
}

int GameData::get_position_number(int x, int y) {
    return this->num[x][y];
}

void GameData::change_position_number(int x, int y, int p) {
    num[x][y] = p;
}

int GameData::get_score() {
    return 0;
}

int GameData::get_best_score() {
    return 0;
}

void GameData::save_data(std::string path = "") {

}

void GameData::read_data(std::string path = "") {

}
