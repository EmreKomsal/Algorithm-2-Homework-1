//
// Created by Emre Komşal on 28.03.2022.
//

#include "Player.h"

Player::Player(int player_board_size, string player_name, int player_ship_amount, int pos_x, int pos_y) {
    name = player_name;
    ship_amount = player_ship_amount;
    player_board = new Board(player_board_size);
    start_x = pos_x;
    start_y = pos_y;
    for (int i = 0; i < ship_amount; ++i) {
        int x,y,x1,y1;
        cout << "Give Loc \n";
        cin >> x >> y >> x1 >> y1;
        DeployShips(x, y, x1, y1);
    }
    player_board->printNodes();
}

void Player::DeployShips( int x0, int y0, int x1, int y1){
    this->player_board->DeployPlayerShips(x0, y0, x1, y1);
    if (x0 == x1){
        total_size += y1 - y0;
    }
    else if (y0 == y1){
        total_size += x1 - x0;
    }
}
