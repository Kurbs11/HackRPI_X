#include <iostream>
#include <random>
#include <stdlib.h> 
#include <utility>
#include <time.h>

using namespace std;

//This function takes in a board, a string, a starting row and col, a tracking index and a direction and
//searches recusively to see if the string is in the board in that direction. Returns true if found, false if not.
bool search(vector<vector<char> >& board, const string& word, int i, int j, int index, const string& direc){
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
bool exist(vector<vector<char>>& board, const string& word) {
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

//Print function version 1
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

//Print function version 2 (Using this one)
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

//Standard Game Mode
void Standard(char p1char, char p2char){

    int rows = 3;
    int cols = 3;

    int winlen = 3;

    int Tiecount = 0;
    int turn_count = 0;
    int start_check_win = 3;
    bool not_first_time = false;
    bool finished = false;

    //Main Loop of game:
    while(!finished){

        if(not_first_time){
            ++rows;
            ++cols;
            winlen = 4; 
        }

        vector<vector<char> > board(rows, vector<char>(cols, ' '));
        int board_left = rows*cols;
        string p1wincond = string(winlen, p1char);
        string p2wincond = string(winlen, p2char);
        

        std::cout << "Lets play a game of Tic-Tac-Toe(Standard)\n";
        print2(board);

        while(true){
            
            int rowp1 = 0;
            int colp1 = 0;

            cout << "Player 1, make your move(input row then col): "; 
            cin >> rowp1;
            cout << endl;
            cin >> colp1; 
            if ( (rowp1>rows-1 || rowp1 < 0) || (colp1 > cols-1 || colp1 < 0) ) {  //Prevents out-of-bounds access (segmentation fault)
                while ( (rowp1>=rows || rowp1 < 0) || (colp1 >= cols || colp1 < 0) ) {
                    cout << "Please select a valid position (0-" << rows-1 << ")\n";
                    cin >> rowp1;
                    cout << endl;
                    cin >> colp1;
                    cout << endl;
                }
            }

            while (board[rowp1][colp1] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: \n";
                cin >> rowp1;
                cout << endl;
                cin >> colp1;
                cout << endl;
            }

            board[rowp1][colp1] = p1char;
            --board_left;

            cout << endl;
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, p2wincond) ) {
                cout << "You win, Player 2!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Expanding Board ---- Retry\n";
                    cout << "Win 4 in a row\n";
                    ++Tiecount;
                    if (Tiecount == 5) cout << "You guys are either clueless, or here for the memes. Have fun ;)\n";
                    not_first_time = true;
                    break;
                }
            }

            if (turn_count >= (start_check_win) ) {
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
            }

            int rowp2 = 0;
            int colp2 = 0;

            cout << "Player 2, make your move(input row then col): \n"; 
            cin >> rowp2;
            cout << endl;
            cin >> colp2;
            cout << endl; 
            if ( (rowp2>rows-1 || rowp2 < 0)|| (colp2 > cols-1 || colp2 < 0) ) { 
                while ((rowp2>=rows || rowp2 < 0) || (colp2 >= cols || colp2 < 0) ) {
                    cout << "Please select a valid position (0-" << rows-1 << ")\n";
                    cin >> rowp2;
                    cout << endl;
                    cin >> colp2;
                    cout << endl; 
                }
            }

            while (board[rowp2][colp2] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: \n";
                cin >> rowp2;
                cout << endl;
                cin >> colp2;
                cout << endl;
            }

            board[rowp2][colp2] = p2char;
            --board_left;

            cout << endl;
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, p2wincond) ) {
                cout << "You win, Player 2!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Expanding Board ---- Retry\n";
                    cout << "Win 4 in a row\n";
                    ++Tiecount;
                    if (Tiecount == 5) cout << "You guys are either clueless, or here for the memes. Have fun ;)\n";
                    not_first_time = true;
                    break;
                }
            }

            if (turn_count >= (start_check_win) ) {
                if ( exist(board, p2wincond) ) {
                    cout << "You win, Player 2!\n";
                    finished = true;
                    break;
                }
            }
        }
    }

}

void Standard_SinglePlayer(char p1char) {
    
    int rows = 3;
    int cols = 3;
    char botchar = '#';
    int winlen = 3;

    int Tiecount = 0;
    int turn_count = 0;
    int start_check_win = 3;
    bool not_first_time = false;
    bool finished = false;

    //Main Loop of game:
    while(!finished){

        if(not_first_time){
            ++rows;
            ++cols;
            winlen = 4; //After the first round, it is win by 4-in-a-row
        }

        vector<vector<char> > board(rows, vector<char>(cols, ' '));
        int board_left = rows*cols;
        string p1wincond = string(winlen, p1char);

        if (p1char == botchar) botchar = '%';
        string botwincond = string(winlen, botchar);
        

        std::cout << "Lets play a game of Tic-Tac-Toe(Standard)\n";
        print2(board);

        while(true){
            
            int rowp1 = 0;
            int colp1 = 0;

            cout << "Player, make your move(input row then col): "; 
            cin >> rowp1;
            cout << endl;
            cin >> colp1; 
            if ( (rowp1>rows-1 || rowp1 < 0) || (colp1 > cols-1 || colp1 < 0) ) {  //Prevents out-of-bounds access (segmentation fault)
                while ( (rowp1>=rows || rowp1 < 0) || (colp1 >= cols || colp1 < 0) ) {
                    cout << "Please select a valid position (0-" << rows-1 << ")\n";
                    cin >> rowp1;
                    cout << endl;
                    cin >> colp1;
                    cout << endl;
                }
            }

            while (board[rowp1][colp1] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: \n";
                cin >> rowp1;
                cout << endl;
                cin >> colp1;
                cout << endl;
            }

            board[rowp1][colp1] = p1char;
            --board_left;

            cout << endl;
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, botwincond) ) {
                cout << "You lose!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Expanding Board ---- Retry\n";
                    cout << "Win 4 in a row\n";
                    ++Tiecount;
                    if (Tiecount == 5) cout << "We do a bit of trollin... Have fun ;)\n";
                    not_first_time = true;
                    break;
                }
            }

            if (turn_count >= (start_check_win) ) {
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
            }

            
            //Loops through all available spaces so the bot can "choose" a valid location
            vector < pair <int, int > > available_spaces;
            for ( int i = 0; i < rows; i++) {
               for ( int j = 0; j < cols; j++) {
                    if (board[i][j] == ' ') {
                        pair < int, int > open_spot;
                        open_spot.first = i;
                        open_spot.second = j;
                        available_spaces.push_back(open_spot);
                    }
               }
            }
            srand (time(NULL)); //This call makes the numbers different every playthrough
            int randomnum = rand()%available_spaces.size(); //Choses a random index for the available spaces vector
            
            
            int randomrow = available_spaces[randomnum].first; 
            int randomcol = available_spaces[randomnum].second;

            cout << "Calculating Moves... \n"; 
            
            cout << "Selecting " <<  randomrow << " " << randomcol << "\n";
            
            //Don't need error checking for bot, as it always searches for exclusively valid locations

            board[randomrow][randomcol] = botchar;
            --board_left;

            cout << endl;
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, botwincond) ) {
                cout << "You lose!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Expanding Board ---- Retry\n";
                    cout << "Win 4 in a row\n";
                    ++Tiecount;
                    if (Tiecount == 5) cout << "You guys are either clueless, or here for the memes. Have fun ;)\n";
                    not_first_time = true;
                    break;
                }
            }

            if (turn_count >= (start_check_win) ) {
                if ( exist(board, botwincond) ) {
                    cout << "You just lost to a bot! \n";
                    finished = true;
                    break;
                }
            }
        }
    }

}

//Educational Game Mode
void Educational(char p1char, char p2char){

    int rows = 3;
    int cols = 3;
    int winlen = 3;
    int start_check_win = 3;
    bool finished = false;
    int num_size = 12; //Default biggest number in each math question

    vector <char> operations;
    operations.push_back('+');
    operations.push_back('-');
    operations.push_back('*');

    while(!finished){
        
        vector<vector<char> > board(rows, vector<char>(cols, ' '));
        int board_left = rows*cols;
        string p1wincond = string(winlen, p1char);
        string p2wincond = string(winlen, p2char);
        int turn_count = 0;
        std::cout << "Lets play a game of Tic-Tac-Toe!\n";
        print2(board);

        while (true){
            
            
            int rowp1 = 0;
            int colp1 = 0;

            cout << "Player 1, make your move(input row then col): "; 
            cin >> rowp1;
            cout << endl;
            cin >> colp1; 
            if ( (rowp1>rows-1 || rowp1 < 0) || (colp1 > cols-1 || colp1 < 0) ) {  //Prevents out-of-bounds access (segmentation fault)
                while ( (rowp1>=rows || rowp1 < 0) || (colp1 >= cols || colp1 < 0) ) {
                    cout << "Please select a valid position (0-" << rows-1 << ")\n";
                    cin >> rowp1;
                    cout << endl;
                    cin >> colp1;
                    cout << endl;
                }
            }

            while (board[rowp1][colp1] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: \n";
                cin >> rowp1;
                cout << endl;
                cin >> colp1;
                cout << endl;
            }

            srand (time(NULL)); //This call makes the numbers different every playthrough
            int randomnum1 = rand()%num_size;
            int randomnum2 = rand()%num_size;
            int randomoperation = rand()%3; //Used for choosing between +/-/*
            cout << "What is " << randomnum1 << operations[randomoperation] << randomnum2 << "? ";
            if (operations[randomoperation] == '+') {
                int correct_answer = randomnum1 + randomnum2;
                int response = 0;
                cin >> response; 
                if (response == correct_answer){
                    board[rowp1][colp1] = p1char;
                    --board_left;
                }
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
                if (response == correct_answer){
                    board[rowp1][colp1] = p1char;
                    --board_left;
                }
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
                if (response == correct_answer){
                    board[rowp1][colp1] = p1char;
                    --board_left;
                }
                else {
                    cout << "Incorrect, " << randomnum1 << "x" << randomnum2 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";
                    turn_count--;
                    
                }
            }

            cout << endl; 
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0  ){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, p2wincond) ) {
                cout << "You win, Player 2!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Try Again ----\n";
                    num_size += 5;
                    cout << "Moderately Increasing Mathematic Difficulty...\n";
                    break;
                }
            }
            if (turn_count >= (start_check_win) ) {
                if ( exist(board, p1wincond) ) {
                    cout << "You win, Player 1!\n";
                    finished = true;
                    break;
                }
            }

            int rowp2 = 0;
            int colp2 = 0;

            cout << "Player 2, make your move(input row then col): \n"; 
            cin >> rowp2;
            cout << endl;
            cin >> colp2;
            cout << endl; 
            if ( (rowp2>rows-1 || rowp2 < 0)|| (colp2 > cols-1 || colp2 < 0) ) { 
                while ((rowp2>=rows || rowp2 < 0) || (colp2 >= cols || colp2 < 0) ) {
                    cout << "Please select a valid position (0-" << rows-1 << ")\n";
                    cin >> rowp2;
                    cout << endl;
                    cin >> colp2;
                    cout << endl; 
                }
            }

            while (board[rowp2][colp2] != ' ') { //Standard Mode, Placing in incorrect spot
                cout << "Select an unpopulated position: \n";
                cin >> rowp2;
                cout << endl;
                cin >> colp2;
                cout << endl;
            }

            srand (time(NULL)); //This call should make the numbers different every playthrough
            int randomnum3 = rand()%12;
            int randomnum4 = rand()%12;
            int randomoperation2 = rand()%3; //Used for choosing between +/-/*
            cout << "What is " << randomnum3 << operations[randomoperation2] << randomnum4 << "? ";
            if (operations[randomoperation2] == '+') {
                int correct_answer = randomnum3 + randomnum4;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) {
                board[rowp2][colp2] = p2char;
                board_left--;
                }
                else {
                    cout << "Incorrect, " << randomnum3 << "+" << randomnum4 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";    
                    turn_count--;
                }
            }

            else if (operations[randomoperation2] == '-') {
                int correct_answer = randomnum3 - randomnum4;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) {
                board[rowp2][colp2] = p2char;
                board_left--;
                }
                else {
                    cout << "Incorrect, " << randomnum3 << "-" << randomnum4 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn..." << "\n";
                    turn_count--;
                    
                }
            }

            else if (operations[randomoperation2] == '*') {
                int correct_answer = randomnum3 * randomnum4;
                int response = 0;
                cin >> response; 
                if (response == correct_answer) {
                    board[rowp2][colp2] = p2char;
                    board_left--; }
                else {
                    cout << "Incorrect, " << randomnum3 << "x" << randomnum4 << "=" << correct_answer << "\n";
                    cout << "Skipping Turn" << "\n";
                    turn_count--;
                    
                }
            }
            
            cout << endl;
            print2(board);
            cout << endl;
            turn_count++;

            //Check for Tie
            if(board_left == 0){
                if ( exist(board, p1wincond) ) {
                cout << "You win, Player 1!\n";
                finished = true;
                break;
                }
                else if ( exist(board, p2wincond) ) {
                cout << "You win, Player 2!\n";
                finished = true;
                break;
                }
                else{
                    cout << "Tie Game ---- Try Again ----\n";
                    break;
                }
            }

            if (turn_count >= (start_check_win) ) {
                if ( exist(board, p2wincond) ) {
                    cout << "You win, Player 2!\n";
                    finished = true;
                    break;
                }
            }

        }
    }

}


int main(){

    //Mode Select
    cout << "\nWelcome to Twist-Tac-Toe!\n";

    //Print rule board
    cout << "Here is the location guide to the board. This is how you choose the row and column you want to fill.\n";
    vector<vector<char> >demo(3, vector<char>(3, ' '));
    
    demo[0][0] = '0';
    demo[1][0] = '1';
    demo[0][1] = '1';
    demo[2][0] = '2';
    demo[0][2] = '2';
   
    print2(demo);

    cout << "\nStart by selecting Standard or Educational mode: ";
    string mode;
    cin >> mode;
    if (mode!= "Standard" && mode!= "Educational") {
        while (mode!= "Standard" || mode!= "Educational") {
            cout << "Please select a valid mode: ";
           cin >> mode; 
           if (mode== "Standard" || mode== "Educational") break;
        }
    }
    
    char p1char = 'X'; //Classic placeholders 
    char p2char = 'O';

    int style = 0;
    
    cout << "Press 1 for single player and 2 for multiplayer: ";
    cin >> style;
    if (style!= 1 && style!= 2) {
    while (style!= 1 && style!= 2) {
        cout << "Please select a valid player format: ";
        cin >> style; 
        if (style == 1 || style == 2) break;
        }
    }


    //Character Select
    cout << "Player 1, select your character: ";
    cin >> p1char;
    if (style == 2) { 
        cout << "\nPlayer 2, select your character: ";
        cin >> p2char;
        cout << endl;
        if (p2char == p1char) {
            while (p2char == p1char) {
                cout << "Select a different character: ";
                cin >> p2char;
            }
            cout << endl;
        }
    }


    if(mode == "Standard"){
        if (style == 1) Standard_SinglePlayer(p1char);
        else if (style == 2) Standard(p1char, p2char);
    }
    else if(mode == "Educational"){
        Educational(p1char, p2char);
    }

    return 0;
}
//Notes for future versions: Add a more difficult CPU, allow them to be playable in educational mode.