

#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;


Board::Board(int puzzleNum){
 
    ifstream infile;
    this->puzzleNum = puzzleNum;
    //based on number passed into constructor, a different txt file is loaded.
    switch(puzzleNum){
        case 1: infile.open("S1.txt");
        break;
        case 2: infile.open("S2.txt");
        break;
        case 3: infile.open("S3.txt");
        break;
        case 4: infile.open("S4.txt");
        break;
        case 5: infile.open("S5.txt");
        break; 
        default: cout << "Invalid puzzle # given." <<endl;
        exit(0);
    }
    
    try{
        if(!infile)
            throw string("puzzle file not found");    //check for solution file
    }
    catch(string msg){ //exits program if file isn't loaded
        cerr << msg << endl;
        exit(0);
    }
   
    int num;
    
    //initializes columnHints array
    for(int i = 0; i < HINT_SIZE; i++){
        infile >> num;
        columnHints[i] = num;
        //cout << columnHints[i] << " ";
    }
    //initializes rowHints array
    for(int i = 0; i < HINT_SIZE; i++){
        infile >> num;
        rowHints[i] = num;
        //cout << rowHints[i] << " ";
    }
    //initializes boardSol array with proper solution
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            infile >> num;
            boardSol[i][j] = num;
        }
    }
    //initializes board array with 0s 
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = 0;
        }
    }    
}
void Board::ShowBoard(){
    
    int hintNum = 0;
    //int colHints = 0;
    //Shows and spaces column hints
    
    for(int i = 0; i < BOARD_SIZE/2; i++){
        cout << "    || ";
        for(int j = 0; j < BOARD_SIZE; hintNum++, j++){
            cout << this->columnHints[hintNum] << " ";
        }
        cout << endl;
    }
    hintNum = 0;
    cout << "--------------" << endl;
    //Shows 2 row hints per row
    for(int i = 0; i < BOARD_SIZE; i++){  
        for(int k = 0; k < 2; hintNum++,k++){
            cout << this->rowHints[hintNum] << " ";
        }
        cout << "|| ";
        //Prints board[][] contents after the hints
        for(int j = 0; j < BOARD_SIZE; j++){
            cout << this->board[i][j] << " " ;
        }
        cout << ":Row " << i+1 << endl;
    }
    cout << "--------------" << endl <<"Column 1 2 3 4 " << endl;  
    
}
void Board::UserInput(){
    
    int row, column = 0;
    char answer = 'x';
    //do-while loop that takes user input and changes board[][] from 0 to 1
    //continues until answer == 'N'
    do{
        cout << "Which row would you like to change?" << endl;
        cin >> row;
        //cin.ignore();
        
        while(row < 1 || row > 4){
            cout << "Input valid row." << endl;
            cin >> row;
           // cin.ignore();
            
        }
        row-=1; //to convert to proper array index
        
        cout << "Which column would you like to change?" << endl;
        cin >> column;
        //cin.ignore();
        
        while(column < 1 || column > 4){
            cout << "Input valid column." << endl;
            cin >> column;
            //cin.ignore();
            
        }
        column-=1; //to convert to proper array index
        
        if(board[row][column] == 0){
            board[row][column] = 1;
        }
        else{
            board[row][column] = 0;
        }
        ShowBoard();
        
        cout << "Add more changes? (Y/N)" << endl;
        cin >> answer;
    }while(answer != 'N');
}
bool Board::Check(){
    bool status = true;
    for(int i = 0; i < BOARD_SIZE; i++){
        int numW = 0;
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] != boardSol[i][j]){
               numW++;
               status = false;
            }
        }
        cout << "Row " << i + 1 <<" has " << numW << " errors." << endl;
    }
    if(status == false)
        return status;
    cout << "Correct" << endl;
    status = true;
    return status;
}
void Board::Save(){
    ofstream outfile;
    outfile.open("out.txt");
    outfile << puzzleNum << "\r\n";   
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            outfile << board[i][j] << " ";
        }
    }
    outfile.close();
}
void Board::Load(){
    
    ifstream infile;
    infile.open("out.txt");
    
    infile >> puzzleNum;
    
    int num;
    
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            infile >> num;
            board[i][j] = num;
        }
    }
    
    infile.close();
    
    //based on number passed into constructor, a different txt file is loaded.
    switch(puzzleNum){
        case 1: infile.open("S1.txt");
        break;
        case 2: infile.open("S2.txt");
        break;
        case 3: infile.open("S3.txt");
        break;
        case 4: infile.open("S4.txt");
        break;
        case 5: infile.open("S5.txt");
        break; 
        default: cout << "Invalid puzzle # given." <<endl;
        exit(0);
    }
    
    try{
        if(!infile)
            throw string("puzzle file not found");    //check for solution file
    }
    catch(string msg){ //exits program if file isn't loaded
        cerr << msg << endl;
        exit(0);
    }
    
    
    //initializes columnHints array
    for(int i = 0; i < HINT_SIZE; i++){
        infile >> num;
        columnHints[i] = num;
        //cout << columnHints[i] << " ";
    }
    //initializes rowHints array
    for(int i = 0; i < HINT_SIZE; i++){
        infile >> num;
        rowHints[i] = num;
        //cout << rowHints[i] << " ";
    }
    //initializes boardSol array with proper solution
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            infile >> num;
            boardSol[i][j] = num;
        }
    }
}


