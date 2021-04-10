#include <iostream>
#include "TicTacToe.h"

#define __CLEAR_SCREEN__ std::cout << "\033c"

// Pawel Zabinski //
// 10th April 2021 //
// Tic Tac Toe Game //
// Object Oriented Programming //

int main()
{
  TicTacToe main;

  while (!main.GameOver)
  {
    main.displayBoard();
    main.getInput();

    main.checkGameStatus();

    __CLEAR_SCREEN__;
  }
}
