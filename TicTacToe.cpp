#include "TicTacToe.hpp" 

Game::Game() {
    setUserChar();
    solvable_ = false;
    numOfSpaces = 9;

    makeBoard();

    display();

    playGame();
}

void Game::makeBoard() {

    board = new char*[3]; // dynamically create an array of pointers of size `M` (creates 3x1 row)

    for (int i = 0; i < 3; i++) { // dynamically allocate memory of size `N` for each row (creates 3X1 column for each row)
        board[i] = new char[3];
    }

    for (int i = 0; i < 3; i++) // assign 0 to the allocated memory to show its empty
    {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '.';
        }
    }
}

void Game::playGame() {
    while (solvable_ != true) {
        if (numOfSpaces != 0) {
            placeFirstUserTile();
            std::cout << std::endl;
            display();
            if (checkWin() == true) {
                solvable_ = true;
                std::cout << "\nFirst Player Won!" << std::endl;
                return;
            } 
        }
            
        if (numOfSpaces != 0) {
            placeSecondUserTile();
            std::cout << std::endl;
            display();
            if (checkWin() == true) {
                solvable_ = true;
                std::cout << "\nSecond Player Won!" << std::endl;
                return;
            }
        }

        if (numOfSpaces == 0 && solvable_ == false) {
            std::cout << "\nDRAW" << std::endl;
            return;
        }
    }
}

void Game::display() {
    // print the 2D array
    for (int i = 0; i < 3; i++) //rows 
    {
        if ((i != 0) && (i % 1 == 0)){
            std::cout << "- - - - - -\n";
        }
        for (int j=0; j < 3; j++) { //columns
            if ((j != 0) && (j % 1 == 0)) {
                std::cout << "|";
            }
            std::cout << " " << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Game::checkIfEmpty(int i, int j) {
    if ((i<3) && (i>-1) && (j<3) && (j>-1) && (board[i][j] == '.')) {
        return true;
    }
    else {
        return false;
    }
}

void Game::setUserChar() {
    std::cout << "First player, what would you like to be?\n 1) X \n 2) O" << std::endl;

    std::cin >> firstUser_;

    if ((firstUser_ == 'X') || (firstUser_ == 'O')) {
        std::cout << "You are now: " << firstUser_ << std::endl;
        if (firstUser_ == 'X') {
            secondUser_ = 'O';
        }
        else {
            secondUser_ = 'X';
        }
        std::cout << "Second player, you are: " << secondUser_ << std::endl;
    }
    else if ((firstUser_ == 'x') || (firstUser_ == 'o')){
        std::cout << "DID I SAY YOU CAN MAKE IT LOWER CASE!?!?! REPLY WITH ONLY X OR O\n" << std::endl;
        setUserChar();
    }  
    else {
        std::cout << "Try again loser\n" << std::endl;
        setUserChar();
    } 
}

bool Game::placeFirstUserTile() {
    std::cout << "\nFirst player, place a tile. First enter the row. Then enter the column.\n";
    std::cin >> row >> col;
    row -= 1;
    //std::cin >> col;
    col -= 1;

    // check if that input is empty / valid
    if (checkIfEmpty(row, col)) {
        board[row][col] = firstUser_;
        numOfSpaces--;
    }
    else {
        std::cout << "\nIncorrect input! Re-enter!" << std::endl;
        display();
        placeFirstUserTile();
    }

    return true;
}

bool Game::placeSecondUserTile() {
    std::cout << "\nSecond player, place a tile. First enter the row. Then enter the column.\n";
    std::cin >> row >> col;
    row -= 1;
    //std::cin >> col;
    col -= 1;

    if (checkIfEmpty(row, col)) {
        board[row][col] = secondUser_;
        numOfSpaces--;
        return true;
    }
    else {
        std::cout << "\nIncorrect input! Re-enter!" << std::endl;
        display();
        placeSecondUserTile();
    }

    return false;
}

bool Game::checkWin() {

    for (int i = 0; i < 3; i++) { //check rows
        if ((board[i][0] == firstUser_ && board[i][1] == firstUser_ && board[i][2] == firstUser_) 
        || (board[i][0] == secondUser_ && board[i][1] == secondUser_ && board[i][2] == secondUser_)) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) { //check cols
        if ((board[0][i] == firstUser_ && board[1][i] == firstUser_ && board[2][i] == firstUser_) 
        || (board[0][i] == secondUser_ && board[1][i] == secondUser_ && board[2][i] == secondUser_)) {
            return true;
        }
    }

    //check diagnols
    if ((board[0][0] == firstUser_ && board[1][1] == firstUser_ && board[2][2] == firstUser_) 
    || (board[0][0] == secondUser_ && board[1][1] == secondUser_ && board[2][2] == secondUser_)) {
        return true;
    }
    if ((board[0][2] == firstUser_ && board[1][1] == firstUser_ && board[2][0] == firstUser_) 
    || (board[0][2] == secondUser_ && board[1][1] == secondUser_ && board[2][0] == secondUser_)) {
        return true;
    }

    for (int i = 0; i < 3; i++) { //check for emptiness
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '.') {
                return false;
            }
        }
    }

    return false;
}