//
// Created by Emre Komşal on 28.03.2022.
//

#include "Player.h"

Player::Player(string filename, string player_name) {
    //Open given File
    fstream playerfile;
    playerfile.open(filename);
    int board_size = 0;
    if (playerfile.is_open()){
        playerfile >> search_method >> start_x >> start_y >> board_size >> ship_amount;
    } else {
        cout << "File could not opened \n";
    }
    name = std::move(player_name);
    player_board = new Board(board_size);
    for (int i = 0; i < ship_amount; ++i) {
        int x,y,x1,y1;
        playerfile >> x >> y >> x1 >> y1;
        DeployShips(x, y, x1, y1);
    }
    playerfile.close();
    //DEBUG CODE
    cout << "\n \t" << name << ", " << total_size;
    player_board->printNodes();
}

void Player::DeployShips( int x0, int y0, int x1, int y1){
    this->player_board->DeployPlayerShips(x0, y0, x1, y1);
    if (x0 == x1){
        total_size += y1 - y0 + 1;
    }
    else if (y0 == y1){
        total_size += x1 - x0 + 1;
    }
}

//Uyanınca burayı kurcala
void Player::FindTargetQue_DFS() {
    Node* target_node = attack_qeue.front();
    if (target_node->isVisited){
        visitedNodes.push_back(target_node);
    }
    attack_qeue.pop_front();
    if (target_node->right && !target_node->right->isVisited){
        attack_qeue.push_front(target_node->right);
    }
    if (target_node->down && !target_node->down->isVisited){
        attack_qeue.push_front(target_node->down);
    }
    if (target_node->left && !target_node->left->isVisited){
        attack_qeue.push_front(target_node->left);
    }
    if (target_node->up && !target_node->up->isVisited){
        attack_qeue.push_front(target_node->up);
    }
}

void Player::FindTargetQue_BFS() {
    Node* target_node = attack_qeue.front();
    if (target_node->isVisited){
        visitedNodes.push_back(target_node);
    }
    attack_qeue.pop_front();
    if (target_node->up && !target_node->up->isVisited){
        attack_qeue.push_back(target_node->up);
        number_of_node_kept_in_mem++;
    }
    if (target_node->left && !target_node->left->isVisited){
        attack_qeue.push_back(target_node->left);
        number_of_node_kept_in_mem++;
    }
    if (target_node->down && !target_node->down->isVisited){
        attack_qeue.push_back(target_node->down);
        number_of_node_kept_in_mem++;
    }
    if (target_node->right && !target_node->right->isVisited){
        attack_qeue.push_back(target_node->right);
        number_of_node_kept_in_mem++;
    }
}

void Player::AttackToRival(){
    if (attack_qeue.size() == 0){
        Node* attacking_node = rival_player->player_board->FindNode(start_x, start_y);
        attack_qeue.push_front(attacking_node);
        number_of_node_kept_in_mem++;
    }
    else if (search_method == "DFS"){
        FindTargetQue_DFS();
    }
    else if (search_method == "BFS"){
        FindTargetQue_BFS();
    }
    bool isHit = rival_player->player_board->HitOrMiss(attack_qeue.front());
    if (isHit){
        rival_player->total_size--;
    }
}
