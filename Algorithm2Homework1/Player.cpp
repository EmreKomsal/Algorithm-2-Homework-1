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
void Player::FindTargetQue() {
    Node* target_node = attack_qeue.front();
    if (target_node->isVisited){
        visitedNodes.push_back(target_node);
    }
    attack_qeue.pop();
    if (target_node->up){
        attack_qeue.push(target_node->up);
    }
    if (target_node->left){
        attack_qeue.push(target_node->left);
    }
    if (target_node->down){
        attack_qeue.push(target_node->right);
    }
    if (target_node->right){
        attack_qeue.push(target_node->right);
    }
}

void Player::AttackToRival(){
    if (attack_qeue.size() == 0){
        Node* attacking_node = rival_player->player_board->FindNode(start_x, start_y);
        attack_qeue.push(attacking_node);
    }
    else{
        FindTargetQue();
    }
    bool isHit = rival_player->player_board->HitOrMiss(attack_qeue.front());
    if (isHit){
        rival_player->total_size--;
    }
}
