#include "Engine.h"

#include <cassert>
#include <cstdlib>
#include <ctime>

#include "GameBoard.h"

Engine::Engine() :
	m_board(new GameBoard()),
	m_winStatus(WIN_NONE),
	m_winner(NoMarker)
{}

Engine::~Engine()
{}

void Engine::init()
{
	startNewGame();
}

void Engine::startNewGame()
{
	srand(time(NULL));
	m_board->resetBoard();
	m_winStatus = WIN_NONE;
	m_winner = NoMarker;

	if (rand() % 2 == 1)
	{
		makeAIMove();
	}
}

void Engine::onCellPress(unsigned x, unsigned y)
{
	assert(x < 3 && y < 3);

	if (m_winStatus != WIN_NONE ||
		m_board->getCellValue(x, y) != NoMarker)
	{
		return;
	}

	m_board->setCellValue(x, y, player);

	checkWin();

	if (m_winStatus == WIN_NONE)
	{
		makeAIMove();
	}
}

EMarkers Engine::getCellValue(unsigned x, unsigned y) const
{
	assert(x < 3 && y < 3);

	return m_board->getCellValue(x, y);
}

EWin Engine::getWin() const
{
	return m_winStatus;
}

EMarkers Engine::getWinner() const
{
	return m_winner;
}

void Engine::checkWin()
{
	// WARNING: Some bad-quality code (too much of it)


	// Check rows
	if (m_board->getCellValue(0, 0) != NoMarker &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(1, 0) &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(2, 0))
	{
		m_winner = m_board->getCellValue(0, 0);
		m_winStatus = WIN_ROW_1;

		return;
	}
	if (m_board->getCellValue(0, 1) != NoMarker &&
		m_board->getCellValue(0, 1) == m_board->getCellValue(1, 1) &&
		m_board->getCellValue(0, 1) == m_board->getCellValue(2, 1))
	{
		m_winner = m_board->getCellValue(0, 1);
		m_winStatus = WIN_ROW_2;

		return;
	}
	if (m_board->getCellValue(0, 2) != NoMarker &&
		m_board->getCellValue(0, 2) == m_board->getCellValue(1, 2) &&
		m_board->getCellValue(0, 2) == m_board->getCellValue(2, 2))
	{
		m_winner = m_board->getCellValue(0, 2);
		m_winStatus = WIN_ROW_3;

		return;
	}

	// Check columns
	if (m_board->getCellValue(0, 0) != NoMarker &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(0, 1) &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(0, 2))
	{
		m_winner = m_board->getCellValue(0, 0);
		m_winStatus = WIN_COL_1;

		return;
	}
	if (m_board->getCellValue(1, 0) != NoMarker &&
		m_board->getCellValue(1, 0) == m_board->getCellValue(1, 1) &&
		m_board->getCellValue(1, 0) == m_board->getCellValue(1, 2))
	{
		m_winner = m_board->getCellValue(1, 0);
		m_winStatus = WIN_COL_2;

		return;
	}
	if (m_board->getCellValue(2, 0) != NoMarker &&
		m_board->getCellValue(2, 0) == m_board->getCellValue(2, 1) &&
		m_board->getCellValue(2, 0) == m_board->getCellValue(2, 2))
	{
		m_winner = m_board->getCellValue(2, 0);
		m_winStatus = WIN_COL_3;

		return;
	}

	// Check diagonals
	if (m_board->getCellValue(0, 2) != NoMarker &&
		m_board->getCellValue(0, 2) == m_board->getCellValue(1, 1) &&
		m_board->getCellValue(0, 2) == m_board->getCellValue(2, 0))
	{
		m_winner = m_board->getCellValue(1, 1);
		m_winStatus = WIN_DIAGONAL_UP;

		return;
	}

	if (m_board->getCellValue(0, 0) != NoMarker &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(1, 1) &&
		m_board->getCellValue(0, 0) == m_board->getCellValue(2, 2))
	{
		m_winner = m_board->getCellValue(1, 1);
		m_winStatus = WIN_DIAGONAL_DOWN;

		return;
	}

	for (unsigned i = 0; i < 9; ++i)
	{
		if (m_board->getCellValue(i % 3, i / 3) == NoMarker)
		{
			m_winStatus = WIN_NONE;
			return;
		}
	}

	m_winStatus = WIN_DRAW;
}

void Engine::makeAIMove()
{
	assert(m_winStatus == WIN_NONE);

	unsigned tmp;
	while (true)
	{
		tmp = rand() % 9;
		if (m_board->getCellValue(tmp % 3, tmp / 3) == NoMarker)
		{
			m_board->setCellValue(tmp % 3, tmp / 3, bot);
			break;
		}
	}

	checkWin();
}
