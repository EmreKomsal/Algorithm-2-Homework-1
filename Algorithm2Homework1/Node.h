//
// Muhammed Emre Komsal
//
#pragma once
#ifndef NODE_H
#define NODE_H


class Node{
public:
    int pos_x;//x position of node
    int pos_y;//y position of node

    bool isOccupied = false;//is battleship on it
    bool isHit = false;

    Node(int x, int y){
        pos_x = x;
        pos_y = y;
    }

    void GetHit(){
    }
};


#endif //NODE_H
