//
// Created by Emre Komşal on 28.03.2022.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include "Board.h"

class Player {
public:
    string name = "Name";
    Board* player_board;
    int ship_amount = 0;
    int total_size = 0;
    int start_x, start_y;
    string search_method;

    int number_of_node_kept_in_mem = 0;

    Player* rival_player = nullptr;
    deque<Node*> attack_qeue;
    vector<Node*> visitedNodes;


    Player(string filename, string player_name);

    void DeployShips(int start_x, int start_y, int end_x, int end_y);

    void FindTargetQue_DFS();
    void FindTargetQue_BFS();

    void AttackToRival();
};
#endif //PLAYER_H
