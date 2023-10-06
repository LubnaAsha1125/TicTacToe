#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game {
    public: 
        Game(); //create empty board
        void userInput(); //user chooses where they want to place their tile
        void display();
        void playGame();
        bool checkIfEmpty(int i, int j);
        void setUserChar();
        bool placeFirstUserTile();
        bool placeSecondUserTile();
        bool checkWin();
        void placeComputerTile();

        //things to implement
            // 1) if user wants to be X or O
            // 2) the coordinate of where they want to place, check if valid
    
    private:
        char firstUser_;
        char secondUser_;
        void makeBoard();
        bool solvable_;
        char** board;
        int row, col;
        int numOfSpaces;
};
#endif