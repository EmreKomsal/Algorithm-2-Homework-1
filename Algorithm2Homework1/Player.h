//
// Created by Emre Komşal on 28.03.2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"

class Player {
public:
    string name = "Name";
    Board* player_board;
    int ship_amount = 0;
    int total_size = 0;
    int start_x{};
    int start_y{};

    Player(int player_board_size, string player_name, int player_ship_amount, int pos_x, int pos_y);

    void DeployShips(int start_x, int start_y, int end_x, int end_y);
};


#endif //PLAYER_H
