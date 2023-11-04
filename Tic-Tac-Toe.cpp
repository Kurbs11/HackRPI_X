#include <iostream>
#include <random>
#include <utility>
using namespace std;

//This function takes in a board, a string, a starting row and col, a tracking index and a direction and
//searches recusively to see if the string is in the board in that direction. Returns true if found, false if not.
bool search(vector<vector<char> >& board, const std::string& word, int i, int j, int index, const std::string& direc){
    // base case
    if(index >= int(word.length())){
        // when index is equal to word length, it means our search job is done.
        // and in this case, we don't care if i or j is out of bounds of not.
        return true;
    }

    // boundary checking
    if(i<0 || i>= int(board.size())){
        return false;
    }
    if(j<0 || j>=int(board[0].size())){
        return false;
    }

    // if not equal, then this is not the path we are looking for.
    if(board[i][j] != word[index]){
        return false;
    }

    char c = board[i][j];
    // if it's found, we change it to '0' so we can guarantee to not reuse it while we are still on this path.
    board[i][j]='0';

    // general case
    // if search job is still incomplete, then let's continue searching letter i in all four directions, and if we can find the word in any of these four directions, then we are good.
    if(direc == "E"){
        if(search(board, word, i, j+1, index+1, direc) == true){
            board[i][j] = c;
            return true;
        }
    }
    if(direc == "W"){
    if(search(board, word, i, j-1, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "S"){
    if(search(board, word, i+1, j, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "N"){
    if(search(board, word, i-1, j, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "SE"){
    if(search(board, word, i+1, j+1, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "SW"){
    if(search(board, word, i+1, j-1, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "NE"){
    if(search(board, word, i-1, j+1, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    if(direc == "NW"){
    if(search(board, word, i-1, j-1, index+1, direc) == true){
        board[i][j] = c;
        return true;
    }
    }
    
    // restore board[i][j] to its original value
    board[i][j] = c;
    return false;
}

//This function searches the board for the given string by calling search function for every location in the board for every direction.
//It then returns true if it found it, false if not.
bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    int m=board.size();
    int n=board[0].size();
    // find the first letter of this word
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // if it's true, return true; if not, continue search at next (i,j)
            if(search(board, word, i, j, 0, "E") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "W") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "S") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "N") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "SE") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "SW") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "NE") == true){
                return true;
            }
            if(search(board, word, i, j, 0, "NW") == true){
                return true;
            }
        }
    }
    // if we reach here, then the word can't be found.
    return false;
}


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
    string p1wincond = string(rows, 'O');
    string p2wincond = string(rows, 'X');

    vector<vector<char> > board(rows, vector<char>(cols, ' '));
    int space_left = rows*cols;

    bool finished = false;

    while(!finished){

        print2(board);  

        char p1char = 'O';
        char p2char = 'X';

        int row = 0;
        int col = 0;

        hhhhhhhhhhhhhhhhhh

        pair<int, int> p1choice(row, col);






    }



    





    return 0;
}