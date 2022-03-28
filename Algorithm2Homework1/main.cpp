//Muhammed Emre Komsal
//150160066

//Libraries
#include <iostream>
#include <queue>
#include <vector>

#include "Node.h"
#include "Ship.h"
#include "Board.h"

using namespace std;

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