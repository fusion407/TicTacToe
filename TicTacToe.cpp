/*
    TIC TAC TOE     -      Brady Dorsey
*/

#include <iostream>

bool gameOn = true;
// Just to show off in menu for players reference
void drawBoard() {

    std::cout << "_1_|_2_|_3_\n"
              << "_4_|_5_|_6_\n"
              << "_7_|_8_|_9_\n";
}
// take in new X or O value for each array and update new board on to the screen
void updateBoard(char arr[8]) {
    std::cout << "\n\n";
    std::cout << "_" << arr[0] << "_|_" << arr[1] << "_|_" << arr[2] << "_\n"
              << "_" << arr[3] << "_|_" << arr[4] << "_|_" << arr[5] << "_\n"
              << "_" << arr[6] << "_|_" << arr[7] << "_|_" << arr[8] << "_\n";
}
// Announces the winner of the game and resets loop
void handleWin(char winner) {   
    std::cout << "\nCongratulations, " << winner << " you have won!\n";
    gameOn = false;
}
void checkWin(char mark[], char playerN) {

    // debug
    /*for (int i = 0; i <= 8; i++) {
        if (mark[i] != '_')
        {
            std::cout << mark[i];
        }
        else {
            std::cout << i;
        }
    }*/

    // check for matching triples across the board
    if (mark[0] == playerN && mark[1] == playerN && mark[2] == playerN) {
        handleWin(playerN);
    }
    else if (mark[0] == playerN && mark[3] == playerN && mark[6] == playerN) {
        handleWin(playerN);
    }
    else if (mark[0] == playerN && mark[4] == playerN && mark[8] == playerN) {
        handleWin(playerN);
    }
    else if (mark[3] == playerN && mark[4] == playerN && mark[5] == playerN) {
        handleWin(playerN);
    }
    else if (mark[6] == playerN && mark[7] == playerN && mark[8] == playerN) {
        handleWin(playerN);
    }
    else if (mark[1] == playerN && mark[4] == playerN && mark[7] == playerN) {
        handleWin(playerN);
    }
    else if (mark[2] == playerN && mark[5] == playerN && mark[8] == playerN) {
        handleWin(playerN);
    }
    else if (mark[2] == playerN && mark[4] == playerN && mark[6] == playerN) {
        handleWin(playerN);
    }
    // check to see if all values across the array are holding the variables X or O, if the board is full with no winner we have a tie (duh)
    int boardCount = 0;
    for (int k = 0; k <= 9; k++) {
        if (mark[k] == 'X' || mark[k] == 'O') {
            boardCount++;           
        }
    }
    if (boardCount == 9) {
        std::cout << "Tie!\n";
        gameOn = false;
    }
 
}
// Main loop
void play() {
    char boardMark[9] = { '_','_','_','_','_','_','_','_','_' };
    int response;
    bool xTurn, oTurn;
    bool gameOver = false;
    char players[] = { 'X','O' };    
    // take in player's response, X is first by default
    // this loop will swap turns between X and O and check for a winning triple at end of each turn
    do {
        // check if game is still running, if so proceed with player X's turn
        if (gameOn) {
            xTurn = true;
        }
        else {
            xTurn = false;
        }
        // Player X's turn
        while (xTurn) {
            std::cout << "Player X, it's your turn!\n" << ">>: ";
            std::cin >> response;
            if (response >= 1 && response <= 9 )
            {
                if (boardMark[response - 1] == players[0] || boardMark[response - 1] == players[1])
                {
                    std::cout << "That square has already been taken, try again\n\n";
                }
                else {
                    boardMark[response - 1] = players[0];
                    updateBoard(boardMark);
                    // check if player X won
                    checkWin(boardMark, players[0]);                 
                    xTurn = false;
                }
            }
            else {
                std::cout << "Invalid response, try again\n\n";
            }
        }
        // check if game is still running, if so proceed with player O's turn
        if (gameOn) {
            oTurn = true;
        }
        else {
            oTurn = false;
        }
        // Player O's turn
        while (oTurn) {
            std::cout << "Player O, it's your turn!\n" << ">>: ";
            std::cin >> response;
            if (response >= 1 && response <= 9 || response)
            {
                if (boardMark[response - 1] == players[0] || boardMark[response - 1] == players[1])
                {
                    std::cout << "That square has already been taken, try again\n\n";
                }
                else {
                    boardMark[response - 1] = players[1];
                    updateBoard(boardMark);
                    // check if player O won
                    checkWin(boardMark, players[1]);
                    oTurn = false;
                }
            }
            else {
                std::cout << "Invalid response, try again\n\n";
            }
        }
        // Do I keep looping..?
        if (!gameOn)
        {
            gameOver = true;
        }
    } while (!gameOver);
    return;
 }
 
int main()
{
    char quit_response;
    // Main menu
    std::cout << "Let's play tic tac toe!\n";
    drawBoard();
    std::cout << "Please choose number between 1-9, player X goes first\n";
    // Game loop
    while (gameOn)
    {
        play();
        // After each round, answering Y or y will reset the board, any other response will terminate console
        std::cout << "Would you like to keep playing?(Y/N): ";
        std::cin >> quit_response;
        if (quit_response == 'Y' || quit_response == 'y') {
            gameOn = true;
        }
        else {
            gameOn = false;
        }
    }
    return 0;
}
