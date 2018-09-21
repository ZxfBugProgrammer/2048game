/*
 * this class save all game data
 */
#ifndef INC_2048GAME_GAMEDATA_H
#define INC_2048GAME_GAMEDATA_H

#include <iostream>

class GameData {
public:

    GameData();

    void SetBestRecord(std::string name = "", int bscore = 0);

    //get grid (x,y) number from data
    // 0 for empty
    int GetPositionNumber(int, int);

    //change (x,y) to number P
    void ChangePositionNumber(int, int, int);

    //get my score
    int GetScore();

    //get history best score
    int GetBestScore();

    //check if game can move on
    bool IsGameOver();

    void MakeNewNumber();

    void InitNewGame();

private:
    int num[4][4];
    int score, my_best;
    std::string local_name;
    int local_best;
};


#endif //INC_2048GAME_GAMEDATA_H
