//
// Created by Emre Komşal on 28.03.2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"

class Player {
    string name = "Name";
    Board* player_board;
    int ship_amount;
    int total_size;
    Player(int player_board_size, string player_name, int player_ship_amount);
};


#endif //PLAYER_H
