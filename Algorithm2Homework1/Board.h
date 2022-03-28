//
// Created by ekoms on 28.03.2022.
//
#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Node.h"

using namespace std;


class Board {
public:

    int size;
    int total_node = 0;
    Node* head_node = nullptr;

    Board(int boardSize){
        size = boardSize;
        CreateNodes();
    };
    void CreateNodes(){//Create size x size node list
        Node* traverse_v = nullptr;
        Node* traverse_h = nullptr;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Node* newNode = new Node(i,j);
                if(j==0){
                    if (i == 0){
                        head_node = newNode;
                        traverse_h = head_node;
                        traverse_v = head_node;
                        continue;
                    }
                    traverse_h = newNode;
                }
                if (j > 0){
                    newNode->left = traverse_h;
                    traverse_h->right = newNode;
                    traverse_h = newNode;
                }
                if(i > 0){
                    traverse_v->down = newNode;
                    newNode->up = traverse_v;
                    if (j < size-1){
                        traverse_v = traverse_v->right;
                    } else {
                        traverse_v = newNode;
                        for (int k = 0; k < size - 1; k++) {
                            traverse_v = traverse_v->left;
                        }
                    }
                }
                total_node++;
            }
        }
        cout << "Board Created \n";
    }

    void DeployPlayerShips(int start_x, int start_y, int end_x, int end_y){
        if(start_x == end_x){
            for (int i = start_y; i < end_y + 1; i++) {
                Node* shipNode = FindNode(start_x, i);
                shipNode->isOccupied = true;
            }
        } else{
            for (int i = start_x; i < end_x + 1; i++) {
                Node* shipNode = FindNode(i, start_y);
                shipNode->isOccupied = true;
            }
        }
    }

    Node* FindNode(int pos_x, int pos_y){
        Node* traverse = head_node;
        for (int i = 0; i < pos_x; ++i) {
            traverse = traverse->down;
        }
        for (int i = 0; i < pos_y; ++i) {
            traverse = traverse->right;
        }
        return traverse;
    }

    //DEBUG FUNC
    void printNodes(){
        if(!head_node){
            cout << "Board is Empty";
            return;
        }
        Node* traverse_v = head_node;
        Node* traverse_h = head_node;
        for (int i = 0; i < size; i++) {
            cout << "\n";
            for(int j = 0; j < size; j++){
                cout << "\t";
                cout << traverse_h->pos_x << ", "<<traverse_h->pos_y;
                if (traverse_h->isOccupied){
                    if (traverse_h->isHit){
                        cout << " X";
                    } else {
                        cout << " O";
                    }
                } else {
                    cout << " .";
                }
                traverse_h = traverse_h->right;
            }
            traverse_v = traverse_v->down;
            traverse_h = traverse_v;
        }
    }
};


#endif //BOARD_H
