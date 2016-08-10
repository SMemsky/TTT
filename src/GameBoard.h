#pragma once

#include "EMarker.h"

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void resetBoard();
	void setCellValue(unsigned x, unsigned y, EMarker value);
	EMarker getCellValue(unsigned x, unsigned y) const;
private:
	static const unsigned boardWidth = 3;
	static const unsigned boardHeight = 3;
	static const unsigned boardSize = boardWidth * boardHeight;
private:
	EMarker m_board[boardSize];
};
