//Muhammed Emre Komsal
//150160066

//Libraries
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node;
class Board;
class Ship;

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

class Ship{
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
                Node *current_node = &board->pieces.at(start_x * board_size + i);//get node from board
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
                Node *current_node = &board->pieces.at(i * board_size + start_y);//get node from board
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

int main()
{
    Board board(5);
    board.printNodes();

    Ship ship(1, 0, 1, 2, &board);
    Ship ship2(3, 3, 4, 3, &board);
    cout << "\n";
    board.printNodes();
    ship.printShip();
    ship2.printShip();
    ship.GetHit(1,1);
    board.printNodes();
    ship.printShip();
}