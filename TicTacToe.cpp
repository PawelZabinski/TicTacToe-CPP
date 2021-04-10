#include <iostream>
#include "TicTacToe.h"

#define CLEAR "\033[1;0m"

#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"

TicTacToe::TicTacToe()
  : m_currentPlayer(PlayerRotation::X), GameOver(false)
{
  // Clear Screen //
  std::cout << "\033c";

  for (size_t x {0}; x < 3; x++)
  {
    for (size_t y {0}; y < 3; y++)
    {
      m_Board[x][y] = ' ';
    }
  }
}

auto TicTacToe::displayBoard() -> void
{
  std::cout << MAGENTA;

  // First Row //
  std::cout << CYAN << m_Board[0][0] << MAGENTA << " ¦ " << CYAN << m_Board[0][1] << MAGENTA << " ¦ " << CYAN << m_Board[0][2] << MAGENTA << std::endl;
  // Divider //
  std::cout << "---------" << std::endl;

  // Second Row //
  std::cout << CYAN << m_Board[1][0] << MAGENTA << " ¦ " << CYAN << m_Board[1][1] << MAGENTA << " ¦ " << CYAN << m_Board[1][2] << MAGENTA << std::endl;

  // Divider //
  std::cout << "---------" << std::endl;

  // Third Row //
  std::cout << CYAN << m_Board[2][0] << MAGENTA << " ¦ " << CYAN << m_Board[2][1] << MAGENTA << " ¦ " << CYAN << m_Board[2][2] << MAGENTA << std::endl;

  std::cout << CLEAR;
}

auto TicTacToe::getInput() -> void
{
  TicTacToeSquare Square;

  std::cout << CYAN;
  // Take Column Input //
  std::cout << "\nPlayer " << (char)(m_currentPlayer) << " - Pick Which Column [1 - 3] -> ";
  std::cin >> Square.column;

  // Take Row Input //
  std::cout << "Player " << (char)(m_currentPlayer) << " - Pick Which Row [1 - 3] -> ";
  std::cin >> Square.row;
  
  std::cout << CLEAR;

  // Make Sure User Input is in Bounds //
  if ((Square.column > 3 || Square.column < 1) || (Square.row > 3 || Square.row < 1))
  {
    std::cout << RED << "[INVALID COMBINATION]" << CLEAR << std::endl;
    exit(0);
  }

  Square.column--;
  Square.row--;
  
  // Update Board if Position is Not Taken //
  if (!isPositionOccupied(Square))
  {
    updateBoard(Square);
    changePlayer();
  }
}

inline auto TicTacToe::updateBoard(TicTacToeSquare Square) -> void
{
  m_Board[Square.column][Square.row] = (char)(m_currentPlayer);
}

inline auto TicTacToe::changePlayer() -> void
{
  if (m_currentPlayer == PlayerRotation::X)
    m_currentPlayer = PlayerRotation::O;
  else
    m_currentPlayer = PlayerRotation::X;
}

auto TicTacToe::isPositionOccupied(TicTacToeSquare Square) -> bool
{
  if (m_Board[Square.column][Square.row] == ' ')
    return false;
  
  return true;
}

auto TicTacToe::checkGameStatus() -> void
{
  //
  //
  // Check If Player X Has Won //
  //
  //
  if(m_Board[0][0] == 'X' && m_Board[0][1] == 'X' && m_Board[0][2] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[1][0] == 'X' && m_Board[1][1] == 'X' && m_Board[1][2] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[2][0] == 'X' && m_Board[2][1] == 'X' && m_Board[2][2] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[0][0] == 'X' && m_Board[1][0] == 'X' && m_Board[2][0] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[0][1] == 'X' && m_Board[1][1] == 'X' && m_Board[2][1] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[0][2] == 'X' && m_Board[1][2] == 'X' && m_Board[2][2] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[0][0] == 'X' && m_Board[1][1] == 'X' && m_Board[2][2] == 'X')
    playerWon(PlayerRotation::X);

  else if(m_Board[2][0] == 'X' && m_Board[1][1] == 'X' && m_Board[0][2] == 'X')
    playerWon(PlayerRotation::X);

  //
  //
  // Check If Player O Has Won //
  //
  //
  if(m_Board[0][0] == 'O' && m_Board[0][1] == 'O' && m_Board[0][2] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[1][0] == 'O' && m_Board[1][1] == 'O' && m_Board[1][2] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[2][0] == 'O' && m_Board[2][1] == 'O' && m_Board[2][2] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[0][0] == 'O' && m_Board[1][0] == 'O' && m_Board[2][0] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[0][1] == 'O' && m_Board[1][1] == 'O' && m_Board[2][1] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[0][2] == 'O' && m_Board[1][2] == 'O' && m_Board[2][2] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[0][0] == 'O' && m_Board[1][1] == 'O' && m_Board[2][2] == 'O')
    playerWon(PlayerRotation::O);

  else if(m_Board[2][0] == 'O' && m_Board[1][1] == 'O' && m_Board[0][2] == 'O')
    playerWon(PlayerRotation::O);

  // Check If Draw //
  for (size_t x {0}; x < 3; x++)
  {
    for (size_t y {0}; y < 3; y++)
    {
      if (m_Board[x][y] == ' ')
        return;
    }
  }

  tie();
}

auto TicTacToe::playerWon(PlayerRotation player) -> void
{
  std::cout << "\033c";
  displayBoard();

  std::cout << CYAN << "\nPlayer [" << (char)(player) << "] Has Won The Game..." << CLEAR << std::endl;
  exit(0);
}

auto TicTacToe::tie() -> void
{
  std::cout << "\033c";
  displayBoard();

  std::cout << CYAN << "\nGame Concluded in a Tie..." << CLEAR << std::endl;
  exit(0);
}
