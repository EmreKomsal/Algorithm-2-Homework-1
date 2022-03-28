//Muhammed Emre Komşal
//150160066

//Libraries
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int pos_x;//x position of node
    int pos_y;//y position of node

    bool isOccupied = false;//is battleship on it

    Node(int x, int y){
        pos_x = x;
        pos_y = y;
    }
};

class Board{
public:
    int size;
    vector<Node> pieces;
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
                cout << pieces.at(pos).pos_x << ", " << pieces.at(pos).pos_y << "\t";
            }
        }
    }
};

class Battleship{
    //Battleship will be in here
public:
    int size = 0;
    vector<Node> coordinates;
};

int main()
{
    Board board(5);
    board.printNodes();
}