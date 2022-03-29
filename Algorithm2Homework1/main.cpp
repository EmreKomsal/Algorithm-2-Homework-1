//Muhammed Emre Komsal
//150160066

//Libraries
#include <iostream>
#include <queue>
#include <vector>

#include "Player.h"


using namespace std;

int main()
{
    Player player1("game2/player1.txt", "Player1");
    Player player2("game2/player2.txt", "Player2");

    player1.rival_player = &player2;
    player2.rival_player = &player1;

    //Fight until death
    while (player1.total_size > 0 && player2.total_size > 0){
        player1.AttackToRival();
        cout << "\nPlayer1";
        player2.player_board->printVisitedNodes();
        if (player2.total_size == 0){
            cout << "\n Player1 won the game \n";
            break;
        }
        player2.AttackToRival();
        cout << "\nPlayer2";
        player1.player_board->printVisitedNodes();
        if (player1.total_size == 0){
            cout << "\n Player2 won the game \n";
            break;
        }
    }
}