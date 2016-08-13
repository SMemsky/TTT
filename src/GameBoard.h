#pragma once

#include "EMarkers.h"

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

	void resetBoard();
	void setCellValue(unsigned x, unsigned y, EMarkers value);
	EMarkers getCellValue(unsigned x, unsigned y) const;
private:
	static const unsigned boardWidth = 3;
	static const unsigned boardHeight = 3;
	static const unsigned boardSize = boardWidth * boardHeight;
private:
	EMarkers m_board[boardSize];
};
