#include "GameBoard.h"

#include <cassert>

GameBoard::GameBoard() :
	m_board()
{}

GameBoard::~GameBoard()
{}

void GameBoard::resetBoard()
{
	for (unsigned i = 0; i < boardSize; ++i)
	{
		m_board[i] = NoMarker;
	}
}

void GameBoard::setCellValue(unsigned x, unsigned y, EMarkers value)
{
	assert (x < boardWidth && y < boardHeight);

	m_board[x + y * boardWidth] = value;
}

EMarkers GameBoard::getCellValue(unsigned x, unsigned y) const
{
	assert (x < boardWidth && y < boardHeight);

	return m_board[x + y * boardWidth];
}
