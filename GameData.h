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
    void read_data(std::string);

    //get grid (x,y) number from data
    // 0 for empty
    int get_position_number(int, int);

    //change (x,y) number
    void change_position_number(int, int, int);

    //get my score
    int get_score();

    //get history best score
    int get_best_score();

    //save data to file
    //default save to work directory
    void save_data(std::string);

private:
    int num[4][4];
    int score, my_best;
    std::string local_name;
    int local_best;
};


#endif //INC_2048GAME_GAMEDATA_H
