//Muhammed Emre Komsal
//150160066

//Libraries
#include <iostream>
#include <chrono>

#include "Player.h"


using namespace std;

void StatisticWriter(Player* player1, Player* player2, string winner, float running_time);

int main()
{

    string winner;
    Player player1("game1/player1.txt", "Player1");
    Player player2("game1/player2.txt", "Player2");

    player1.rival_player = &player2;
    player2.rival_player = &player1;

    auto start = chrono::high_resolution_clock::now();
    //Fight until death
    while (player1.total_size > 0 && player2.total_size > 0){
        player1.AttackToRival();
        cout << "\nPlayer1";
        player2.player_board->printVisitedNodes();
        if (player2.total_size == 0){
            //cout << "\n Player1 won the game \n";
            winner = "Player1";
            break;
        }
        player2.AttackToRival();
        cout << "\nPlayer2";
        player1.player_board->printVisitedNodes();
        if (player1.total_size == 0){
            //cout << "\n Player2 won the game \n";
            winner = "Player2";
            break;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    StatisticWriter(&player1, &player2, winner, duration.count());
}

void StatisticWriter(Player* player1, Player* player2, string winner, float running_time){
    cout << "The algoritm: " << player1->name << ": " << player1->search_method << ", " << player2->name << ": " << player2->search_method << "\n";
    cout << "The number of visited nodes:" << player1->name << ": " << player1->visitedNodes.size() << ", " << player2->name << ": " << player2->visitedNodes.size() << "\n";
    cout << "The number of nodes kept in the memory:" << player1->name << ": "
        << player1->number_of_node_kept_in_mem << ", " << player2->name << ": " << player2->number_of_node_kept_in_mem << "\n";
    cout << "The result: " << winner << " won!" << "\n";
    cout << "The running time:" << running_time << "\n";
}