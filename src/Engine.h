#pragma once

#include <memory>

#include "EMarkers.h"
#include "EWin.h"

class GameBoard;

class Engine
{
public:
	Engine();
	~Engine();

	void init();
	void startNewGame();

	void onCellPress(unsigned x, unsigned y);
	EMarkers getCellValue(unsigned x, unsigned y) const;

	EWin getWin() const;
	EMarkers getWinner() const;
private:
	void checkWin();
	void makeAIMove();
private:
	static const EMarkers player = Cross;
	static const EMarkers bot = Nought;
private:
	std::shared_ptr<GameBoard> m_board;

	EWin m_winStatus;
	EMarkers m_winner;
};
