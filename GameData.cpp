#include "GameData.h"
#include <iostream>

GameData::GameData() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            num[i][j] = 0;
    score = 0;
}

int GameData::GetPositionNumber(int x, int y) {
    return this->num[x][y];
}

void GameData::ChangePositionNumber(int x, int y, int p) {
    num[x][y] = p;
}

int GameData::GetScore() {
    return 0;
}

int GameData::GetBestScore() {
    return 0;
}

void GameData::SaveData(std::string path = "") {

}

void GameData::ReadData(std::string path = "") {

}
