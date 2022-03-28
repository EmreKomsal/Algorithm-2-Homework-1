//
// Created by ekoms on 28.03.2022.
//
#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Node.h"
#include "Ship.h"


using namespace std;

class Board {
public:
    int size;
    vector<Node*> pieces;
    Board(int boardSize){
        size = boardSize;
        CreateNodes();
    };
    void CreateNodes(){//Create size x size node list
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Node newNode(i,j);
                pieces.push_back(newNode);
            }
        }
    }

    //DEBUG FUNC
    void printNodes(){
        for (int i = 0; i < size; i++) {
            cout << "\n";
            for (int j = 0; j < size; j++) {
                int pos = i * size + j;
                Node* curr_node = &pieces.at(pos);
                cout << pieces.at(pos).pos_x << ", " << pieces.at(pos).pos_y;
                if (curr_node->isOccupied){
                    if (!curr_node->isHit){
                        cout << " O";
                    } else {
                        cout << " X";
                    }
                } else {
                    cout << " .";
                }
                cout << "\t";
            }
        }
    }
};


#endif //BOARD_H
