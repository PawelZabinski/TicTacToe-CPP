#pragma once

enum class PlayerRotation : unsigned char
{
  X = 'X', O = 'O'
};

struct TicTacToeSquare
{
  unsigned short column, row;
};

class TicTacToe
{
private:
  char m_Board[3][3];
  PlayerRotation m_currentPlayer;
public:

  bool GameOver;

  TicTacToe();

  void displayBoard();
  inline void updateBoard(TicTacToeSquare);

  void getInput();
  bool isPositionOccupied(TicTacToeSquare);

  inline void changePlayer();

  void checkGameStatus();
  void playerWon(PlayerRotation player);
  void tie();
};
