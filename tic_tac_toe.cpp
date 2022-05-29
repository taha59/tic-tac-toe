#include <iostream>
#include <vector> 
#include <map>
#include <iterator>

using namespace std;

void display_board(vector < vector< char > > &square){
    //display the board
    for(int i = 0; i < square.size(); i++){
        cout << square[i][0] << " " << square[i][1] << " " << square[i][2] << endl;
    }
}

void print_legal_m(map<vector<int>, int> &m){
    map<vector<int>, int>::iterator it;
    
    for(it = m.begin(); it != m.end(); it++)
    cout << "["<< it->first[0] << ","<< it->first[1] << "] ";
}

int game_status(vector< vector < char > > &board, int row, int col){
    //player 1 -- O
    //player 2 -- X
    
    //check col
    if(board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X')
        return 2;
        
    else if(board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O')
        return 1;
    
    //check rows
    if(board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == 'X')
        return 2;
        
    else if(board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == 'O')
        return 1;
    
    //check lower right diagonal
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') 
        return 2;
    else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        return 1;
        
    //check upper right diagonal
    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') 
        return 2;
    else if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
        return 1;
    
    return 0;
}


int main()
{
    int i;
    int x, y;
    int winner;
    vector < vector < char > > square(3);
    
    //legal moves stored in map for quick deletion
    map<vector<int>, int> legal_m { { {0,0}, 0}, { {0,1}, 0}, { {0,2}, 0}, { {1,0}, 0},
    { {1,1}, 0}, { {1,2}, 0}, { {2,0}, 0}, { {2,1}, 0}, { {2,2}, 0} };
    
    //intialize the 3x3 tic tac toe grid
    for(i = 0; i < square.size(); i++){
        square[i].push_back('E');
        square[i].push_back('E');
        square[i].push_back('E');
    }
    
    while(legal_m.size() > 0){
        
        if(legal_m.size() % 2 == 0){
            cout << "Player 2: Enter where you want to place the X" << endl;
        }
        else{
            cout << "Player 1: Enter where you want to place the O" << endl;
        }
        
        display_board(square);
        
        while(1){
            cout << endl << "Enter an x cord followed by a y cord where x and y are numbers 0-2: ";
            cin >> x >> y;
            
            if ( (x >= 0 && x < 3) && (y >= 0 && y < 3)){
                if(square[x][y] == 'E') 
                    break;
                else {
                    cout << "Illegal move detected, please try the following options: " << endl;
                    print_legal_m(legal_m);
                }
            }
            else
                cout << "x and y cord should be in the range 0-2: " << endl;
        }
        
        if(legal_m.size() % 2 == 0){
            square[x][y] = 'X';
        }
        else{
            square[x][y] = 'O';
        }
        
        //after the slot has filled delete the slot from legal moves
        legal_m.erase({x,y});
        
        //if either player 1 or player 2 wins exit the game
        winner = game_status(square, x, y);
        if (winner != 0) break;
    }
    
    
    display_board(square);
    
    cout << endl << "------------GAME OVER----------------" << endl;
    
    if (winner == 0){
        cout << "Its a Tie!";
    }
    else if(winner == 1){
        cout << "PLayer 1 wins!";
    }
    else {
        cout << "Player 2 wins!";
    }

    return 0;
}

