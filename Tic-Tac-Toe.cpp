#include <iostream>
#include <random>
using namespace std;

void print(const vector<vector<char> >& board){

    for(unsigned int i = 0; i < board.size(); i++){
        
        for(unsigned int k = 0; k < board.size(); k++){
            cout << "   ";
            if(k != board.size()-1){
                cout << "|";
            }
        }
        cout << "\n";
        for(unsigned int j = 0; j < board[0].size(); j++){
            
            cout << " " << board[i][j] << " ";
            if(j != board[0].size() - 1){
                cout << "|";
            }
            
        }
        cout << "\n";
        
        for(unsigned int k = 0; k < board.size(); k++){
            cout << "   ";
            if(k != board.size()-1){
                cout << "|";
            }
        }
        cout << "\n";

        if(i != board.size() - 1){
            cout << string((3*board[0].size()) + (board.size() - 1), '-') << "\n";
        }
    }
}

void print2(const vector<vector<char> >& board){

    for(unsigned int i = 0; i < board.size(); i++){
        for(unsigned int j = 0; j < board[0].size(); j++){
            
            cout << " " << board[i][j] << " ";
            if(j != board[0].size() - 1){
                cout << "|";
            }
            
        }
        cout << "\n";
        
        if(i != board.size() - 1){
            cout << string((3*board[0].size()) + (board.size() - 1), '-') << "\n";
        }

    }

}

int main(){

    int rows = 5;
    int cols = 5;
    vector<vector<char> > board(rows, vector<char>(cols, 'X'));
    int space_left = rows*cols;

    print2(board);


    





    return 0;
}