#include <iostream>
#include <vector> 
#include <map>
#include <iterator>

using namespace std;

class tic_tac_toe {
    public:
    void multiplayer_mode();
    void single_player();
    
    //constructor
    tic_tac_toe();
    
    private:
    vector < vector< char > > board;
    map < vector < int >, int > legal_m;
    
    void print_legal_m();
    int game_status(int, int);
    void display_board();
};

void tic_tac_toe::display_board(){
    //display the board
    for(int i = 0; i < board.size(); i++){
        cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << endl;
    }
}

void tic_tac_toe::print_legal_m(){
    map<vector<int>, int>::iterator it;
    
    for(it = legal_m.begin(); it != legal_m.end(); it++)
        cout << "["<< it->first[0] << ","<< it->first[1] << "] ";
}

tic_tac_toe::tic_tac_toe(){
    
    //intialize the 3x3 tic tac toe grid
    board.resize(3);
    for(int i = 0; i < board.size(); i++){
        board[i].push_back('E');
        board[i].push_back('E');
        board[i].push_back('E');
    }
    
    //initialize the legal moves map
    legal_m = { { {0,0}, 0}, { {0,1}, 0}, { {0,2}, 0}, { {1,0}, 0},
    { {1,1}, 0}, { {1,2}, 0}, { {2,0}, 0}, { {2,1}, 0}, { {2,2}, 0} };
}

int tic_tac_toe::game_status(int row, int col){
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

void tic_tac_toe::multiplayer_mode(){
    int i;
    int x, y;
    int winner;
    
    while(legal_m.size() > 0){
        
        if(legal_m.size() % 2 == 0){
            cout << "Player 2: Enter where you want to place the X" << endl;
        }
        else{
            cout << "Player 1: Enter where you want to place the O" << endl;
        }
        
        display_board();
        
        while(1){
            cout << endl << "Enter an x cord followed by a y cord where x and y are numbers 0-2: ";
            cin >> x >> y;
            
            if ( (x >= 0 && x < 3) && (y >= 0 && y < 3)){
                if(board[x][y] == 'E') 
                    break;
                else {
                    cout << "Illegal move detected, please try the following options: " << endl;
                    print_legal_m();
                }
            }
            else
                cout << "x and y cord should be in the range 0-2: " << endl;
        }
        
        
        if(legal_m.size() % 2 == 0){
            board[x][y] = 'X';
        }
        else{
            board[x][y] = 'O';
        }
        
        //after the slot has filled delete the slot from legal moves
        legal_m.erase({x,y});
        
        //if either player 1 or player 2 wins exit the game
        winner = game_status(x, y);
        if (winner != 0) break;
    }
    
    
    display_board();
    
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
    cout << endl;
}

void tic_tac_toe::single_player(){
    int i, x, y;
    int winner;
    
    srand(time(NULL));
    
    while(legal_m.size() > 0){
        
        if(legal_m.size() % 2 == 1){
            cout << "Your turn: Enter where you want to place the X" << endl;
            display_board();
        }
        
        
        if(legal_m.size() % 2 == 1){
            while(1){
                cout << endl << "Enter an x cord followed by a y cord where x and y are numbers 0-2: ";
                cin >> x >> y;
                
                //check if numbers are in range
                if ( (x >= 0 && x < 3) && (y >= 0 && y < 3)){
                    if(board[x][y] == 'E') 
                        break;
                    else {
                        cout << "Illegal move detected, please try the following options: " << endl;
                        print_legal_m();
                    }
                }
                else
                    cout << "x and y cord should be in the range 0-2: " << endl;
            }
        }
        
        
        if(legal_m.size() % 2 == 1){
            board[x][y] = 'X';
        }
        else{
            
            //randomly select x and y values until a legal pair is found
            do{
                x = rand() % 3;
                y = rand() % 3;
            } while(board[x][y] != 'E');
            
            board[x][y] = 'O';
        }
        
        //after the slot has filled delete the slot from legal moves
        legal_m.erase({x,y});
        
        //if either player 1 or player 2 wins exit the game
        winner = game_status(x, y);
        if (winner != 0) break;
    }
    
    display_board();
    
    cout << endl << "------------GAME OVER----------------" << endl;
    
    if (winner == 0){
        cout << "Its a Tie!";
    }
    else if(winner == 1){
        cout << "Bot wins!";
    }
    else {
        cout << "You win!";
    }
    cout << endl;
}

int main()
{
    int mode;
    cout << "What mode would you like to play?:" << endl << endl;
    cout << "1 --- Multiplayer" << endl;
    cout << "2 --- Single Player" << endl << endl;
    
    tic_tac_toe t;
    
    //keep requesting mode until a correct mode is selected
    do{
        cout << "Mode: ";
        cin >> mode;
        
        if (mode == 1){
            t.multiplayer_mode();
        }
        else if(mode == 2){
            t.single_player();
        }
        else{
            cout << "Incorrect mode. PLease try again!" << endl;
        }
    } while(mode < 1 || mode > 2);
        
    return 0;
}


