//
// Created by ekoms on 28.03.2022.
//
#pragma once
#ifndef SHIP_H
#define SHIP_H

#include "Node.h"
#include "Board.h"
#include <iostream>

using namespace std;

class Ship {
public:
    int size = 0;
    vector<Node*> coordinates; //Hold ship node pointers
    bool isSunk = false;

    //Constructor
    Ship(int start_x, int start_y, int end_x, int end_y, Board* board) {
        int board_size = board->size;//get node size
        if (start_x == end_x){
            size = end_y - start_y + 1;
            if (size < 1){
                cout << "Ship size not valid";
            }
            for (int i = start_y; i <= end_y; i++) {
                Node* current_node = &board->pieces.at(start_x * board_size + i);//get node from board
                if (!current_node->isOccupied){
                    coordinates.push_back(current_node);
                    current_node->isOccupied = true;
                    current_node->occupyingShip = this;
                }
                else {
                    cout << "\n Position occupied " << current_node->pos_x << ", " << current_node->pos_y;
                }
            }
        } else if (start_y == end_y){
            size = end_x - start_x + 1;
            if (size < 1){
                cout << "Ship size not valid";
            }
            for (int i = start_x; i <= end_x; i++) {
                Node* current_node = &board->pieces.at(i * board_size + start_y);//get node from board
                if (!current_node->isOccupied){
                    coordinates.push_back(current_node);
                    current_node->isOccupied = true;
                    current_node->occupyingShip = this;
                }
                else {
                    cout << "\n Position occupied " << current_node->pos_x << ", " << current_node->pos_y;
                }
            }
        }
    }

    void GetHit(int pos_x, int pos_y){
        for (int i = 0; i < size; i++) {
            Node* currentNode = coordinates.at(i);
            int x = currentNode->pos_x;
            int y = currentNode->pos_y;
            if(pos_x == x && pos_y == y){
                currentNode->isHit = true;
                size--;
                coordinates.erase((coordinates.begin() + i));
            }
        }
    }

    //DEBUG PRINTS
    void printShip(){
        cout << "\n";
        for (int i = 0; i < size; i++) {
            Node* current_node = coordinates.at(i);
            cout << "\t" << current_node->pos_x << ", " <<current_node->pos_y;
        }
    }
};


#endif //SHIP_H
