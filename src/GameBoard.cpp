#include "GameBoard.h"

#include <cassert>

GameBoard::GameBoard() :
	m_board()
{
	resetBoard();
}

GameBoard::~GameBoard()
{}

void GameBoard::resetBoard()
{
	for (unsigned i = 0; i < boardSize; ++i)
	{
		m_board[i] = Empty;
	}
}

void GameBoard::setCellValue(unsigned x, unsigned y, EMarker value)
{
	assert(
		x >= 0 &&
		y >= 0 &&
		x < boardWidth &&
		y < boardHeight);

	m_board[x + y * boardWidth] = value;
}

EMarker GameBoard::getCellValue(unsigned x, unsigned y) const
{
	assert(
		x >= 0 &&
		y >= 0 &&
		x < boardWidth &&
		y < boardHeight);

	return m_board[x + y * boardWidth];
}
