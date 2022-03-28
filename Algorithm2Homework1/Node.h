//
// Muhammed Emre Komsal
//
#pragma once
#ifndef NODE_H
#define NODE_H

#include "Ship.h"

class Node{
public:
    int pos_x;//x position of node
    int pos_y;//y position of node

    bool isOccupied = false;//is battleship on it
    Ship* occupyingShip;
    bool isHit = false;

    Node(int x, int y){
        pos_x = x;
        pos_y = y;
    }

    void GetHit(){
        if (isOccupied){
            occupyingShip->GetHit(pos_x, pos_y);
        }
    }
};


#endif //NODE_H
