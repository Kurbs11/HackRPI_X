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
        for(unsigned int j = 0; j < board[0].size(); j++){
            
            cout << " " << board[i][j] << " ";
            if(j != board[0].size() - 1){
                cout << "|"
            }
            
        }
        
        for(unsigned int k = 0; k < board.size(); k++){
            cout << "   ";
            if(k != board.size()-1){
                cout << "|";
            }
        }
    }


}


int main(){

    int row, col = 3;
    vector<vector<char> > board(row, vector<char>(col, '0'));
    int space_left = row*col;

    print(board);


    





    return 0;
}