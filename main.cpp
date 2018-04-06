/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chester Guinto
 *
 * Created on January 8, 2018, 10:48 AM
 */

#include <cstdlib>
#include <iostream>
#include "board.h"

using namespace std;

int main(int argc, char** argv) {
    
    
    Board board(1);
    Board board2(2);
    Board board3(3);
    Board board4(4);
    Board board5(5);
    board.ShowBoard();
    board2.ShowBoard();
    board3.ShowBoard();
    board4.ShowBoard();
    board5.ShowBoard();
    //board.UserInput();
    //board.Save();
    //board.Load();
    //board.ShowBoard();
    
    //bool finished = board.Check();
    return 0;
}

