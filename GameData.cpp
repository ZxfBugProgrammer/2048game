#include "GameData.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

GameData::GameData() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            num[i][j] = 0;
    local_best = score = 0;
}

int GameData::GetPositionNumber(int x, int y) {
    return this->num[x][y];
}

void GameData::ChangePositionNumber(int x, int y, int p) {
    num[x][y] = p;
}

int GameData::GetScore() {
    return this->score;
}

int GameData::GetBestScore() {
    return this->local_best;
}

bool GameData::IsGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (num[i][j] == 0)return false;
            if (i - 1 >= 0 && num[i - 1][j] == num[i][j])return false;
            if (i + 1 < 4 && num[i + 1][j] == num[i][j])return false;
            if (j - 1 >= 0 && num[i][j - 1] == num[i][j])return false;
            if (j + 1 < 4 && num[i][j + 1] == num[i][j])return false;
        }
    }
    return true;
}

void GameData::SetBestRecord(std::string name, int bscore) {
    if (name.empty())local_name = "None";
    local_best = bscore;
}

void GameData::MakeNewNumber() {
    srand((unsigned) time(NULL));
    std::vector<std::pair<int, int> > t;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (num[i][j] == 0)t.push_back(std::make_pair(i, j));
        }
    }
    int fillnum;
    if (rand() % 2)fillnum = 2;
    else fillnum = 4;
    int trand = rand() % t.size();
    ChangePositionNumber(t[trand].first, t[trand].second, fillnum);
}

void GameData::InitNewGame() {
    local_best = std::max(local_best, score);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            num[i][j] = 0;
    score = 0;
}
