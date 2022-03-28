//
// Created by Emre Komşal on 28.03.2022.
//

#include "Player.h"

Player::Player(int player_board_size, string player_name, int player_ship_amount) {
    name = player_name;
    ship_amount = player_ship_amount;
    player_board = new Board(player_board_size);
}
