#include <iostream>
#include <random>
#include <stdlib.h> 
#include <utility>
#include <time.h>

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
    // if we reach here, then there is not a victor
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
    cout << "Welcome to Twist-Tac-Toe!\n";
    cout << "Start by selecting Standard or Educational mode: ";
    string mode = "";
    cin >> mode;
    if (mode!= "Standard" && mode!= "Educational") {
        while (mode!= "Standard" || mode!= "Educational") {
            cout << "Please select a valid mode: ";
           cin >> mode; 
           if (mode== "Standard" || mode== "Educational") break;
        }
    }
    int rows = 3;
    int cols = 3;
    int tie_counter = 0;

    
    vector <char> operations;
    operations.push_back('+');
    operations.push_back('-');
    operations.push_back('*');

    vector<vector<char> > board(rows, vector<char>(cols, ' '));
    int space_left = rows*cols;

    
    bool finished = false;

    char p1char = 'O';
    char p2char = 'X';

    cout << "Player 1, select your character: ";
    cin >> p1char;
    cout << "\nPlayer 2, select your character: ";
    cin >> p2char;
    cout << endl;
    if (p2char == p1char) {
        while (p2char == p1char) {
                cout << "Select a different character: ";
                cin >> p2char;
            }
    }

    print2(board);
    string p1wincond = string(rows, p1char);
    string p2wincond = string(rows, p2char);
    int turn_count = 0;

    //Main Loop of game:
    while(!finished){
        

        int rowp1 = 0;
        int colp1 = 0;

        
        cout << "\nPlayer 1, make your move: "; 
        cin >> rowp1 >> colp1; 
        if ( (rowp1>rows-1 || rowp1 < 0) || (colp1 > cols-1 || colp1 < 0) ) {  //Prevents out-of-bounds access (segmentation fault)
            while ( (rowp1>=rows || rowp1 < 0) || (colp1 >= cols || colp1 < 0) ) {
                cout << "Please select a valid position (0-" << rows-1 << ")";
                cin >> rowp1 >> colp1;
                if ( (rowp1<rows &&  rowp1 >= 0) && (colp1 < cols && colp1 >= 0) ) break; 
            }
        }

        cout << "Test: " << board[rowp1][colp1];
        if (board[rowp1][colp1] == ' ' && mode == "Standard") board[rowp1][colp1] = p1char;
        
        else if (board[rowp1][colp1] == ' ' && mode == "Educational") {
             srand (time(NULL)); //This call should make the numbers different every playthrough
             int randomnum1 = rand()%12;
             int randomnum2 = rand()%12;
             int randomoperation = rand()%3; //Used for choosing between +/-/*
            cout << "What is " << randomnum1 << operations[randomoperation] << randomnum2 << "? ";
            if (operations[randomoperation] == '+') {
                int correct_answer = randomnum1 + randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp1][colp1] = p1char;
                else {
                    cout << "Incorrect, " << randomnum1 << "+" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";    
                    turn_count--;
                }
            }

            else if (operations[randomoperation] == '-') {
                int correct_answer = randomnum1 - randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp1][colp1] = p1char;
                else {
                    cout << "Incorrect, " << randomnum1 << "-" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";
                    turn_count--;
                    
                }
            }

            else if (operations[randomoperation] == '*') {
                int correct_answer = randomnum1 * randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp1][colp1] = p1char;
                else {
                    cout << "Incorrect, " << randomnum1 << "x" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn" << p1char << "\n";
                    turn_count--;
                    
                }
            }
            
        }
        
        else if ( board[rowp1][colp1] != ' ' && mode == "Standard") {
            while (board[rowp1][colp1] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: ";
                cin >> rowp1 >> colp1;
                if (board[rowp1][colp1] == ' ' && rowp1<rows && colp1 <cols ) {
                    board[rowp1][colp1] = p1char;
                    break; }
            }
            
        }
        
        cout << endl; 
        print2(board);
        cout << endl;

        turn_count++;
        if (turn_count >= (rows+cols-1) ) {
             if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
             }
        }
        if (turn_count == rows*cols) { //Meaning last turn has occurred, and
            //there is a tie, since otherwise previous conditional would've executed break
            cout << "Tie!\n!"; //Now increase board dimensions
            tie_counter++;
            break; //Temporary
        }

        int rowp2 = 0;
        int colp2 = 0;
        
        cout << "\nPlayer 2, make your move: "; 
        pair<int, int> p2choice(rowp2, colp2);
        cin >> rowp2 >> colp2; 
        if ( (rowp2>rows-1 || rowp2 < 0)|| (colp2 > cols-1 || colp2 < 0) ) { 
            while ((rowp2>=rows || rowp2 < 0) || (colp2 >= cols || colp2 < 0) ) {
                cout << "Please select a valid position (0-" << rows-1 << ")\n";
                cin >> rowp2 >> colp2;
                if ((rowp2<rows &&  rowp2 >= 0) && (colp2 < cols && colp2 >= 0)) break; 
            }
        }

        if (board[rowp2][colp2] == ' ' && mode == "Standard") board[rowp2][colp2] = p2char; //If index isn't populated

        if (board[rowp2][colp2] == ' ' && mode == "Educational") {
             srand (time(NULL)); //This call should make the numbers different every playthrough
             int randomnum1 = rand()%12;
             int randomnum2 = rand()%12;
             int randomoperation = rand()%3; //Used for choosing between +/-/*
            cout << "What is " << randomnum1 << operations[randomoperation] << randomnum2 << "? ";
            if (operations[randomoperation] == '+') {
                int correct_answer = randomnum1 + randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp2][colp2] = p2char;
                else {
                    cout << "Incorrect, " << randomnum1 << "+" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";    
                    turn_count--;
                }
            }

            else if (operations[randomoperation] == '-') {
                int correct_answer = randomnum1 - randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp2][colp2] = p2char;
                else {
                    cout << "Incorrect, " << randomnum1 << "-" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";
                    turn_count--;
                    
                }
            }

            else if (operations[randomoperation] == '*') {
                int correct_answer = randomnum1 * randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) board[rowp2][colp2] = p2char;
                else {
                    cout << "Incorrect, " << randomnum1 << "x" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn" << p2char << "\n";
                    turn_count--;
                    
                }
            }
            
        }

        else if  (board[rowp2][colp2] != ' ' && mode == "Standard") {
            while (board[rowp2][colp2] != ' ') { //Standard mode, already populated location
                    cout << "Select an unpopulated position: ";
                    cin >> rowp2 >> colp2;
                    
                     if (board[rowp2][colp2] == ' ' && rowp2<rows && colp2 <cols) {
                        board[rowp2][colp2] = p2char;
                        break;
                     }
                }
    }


        cout << endl;
        print2(board);
        cout << endl;
        turn_count++;
        if (turn_count >=5) {
             if ( exist(board, p2wincond) ) {
                cout << "You win, Player 2!";
                finished = true;
                break;
             }
        }

        

    }



    





    return 0;
}