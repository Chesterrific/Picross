

#ifndef BOARD_H
#define BOARD_H

#include <fstream>

using namespace std;

const int BOARD_SIZE = 4;
const int HINT_SIZE = 8;

class Board{    
    
private:
    
    int board[BOARD_SIZE][BOARD_SIZE];      //player board
    int boardSol[BOARD_SIZE][BOARD_SIZE];   //solution board to be compared to
    int columnHints[HINT_SIZE];             
    int rowHints[HINT_SIZE];
    int puzzleNum;
        
public:
    Board(int);
    /*
     * Board constructor, takes in puzzle number to construct board with 
     * proper hints and correct solution board.
     */
    void ShowBoard();  
    /*
     * Displays board with its hints
     */
    void UserInput(); 
    /*
     * changes board based on user input
    */
    bool Check();
    /*
     * checks board vs boardSol for correctness 
     */
    void Save();
    /*
     * saves user board and puzzle number 
     */
    void Load();
    /*
     * loads user board and puzzle
     */
};


#endif /* BOARD_H */

