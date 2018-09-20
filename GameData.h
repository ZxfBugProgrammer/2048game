/*
 * this class save all game data
 */
#ifndef INC_2048GAME_GAMEDATA_H
#define INC_2048GAME_GAMEDATA_H

#include <iostream>

class GameData {
public:

    GameData();

    //read game data from file
    //or do nothing to begin a new game
    void ReadData(std::string);

    //get grid (x,y) number from data
    // 0 for empty
    int GetPositionNumber(int, int);

    //change (x,y) number
    void ChangePositionNumber(int, int, int);

    //get my score
    int GetScore();

    //get history best score
    int GetBestScore();

    //save data to file
    //default save to work directory
    void SaveData(std::string);

private:
    int num[4][4];
    int score, my_best;
    std::string local_name;
    int local_best;
};


#endif //INC_2048GAME_GAMEDATA_H
