#include "Interface.h"

#include "Game.h"
#include "Widget.h"

Interface::Interface(Game* game) :
	m_game(game),
	m_rootWidget(nullptr)
{
	m_rootWidget = new Widget();
	m_rootWidget->setParent(nullptr); // Is this necessary?
}

Interface::~Interface()
{
	if (m_rootWidget != nullptr)
	{
		delete m_rootWidget;
	}
}

void Interface::init()
{

}

void Interface::tick(double deltaTime)
{

}

void Interface::draw()
{

}

Widget* Interface::getRootWidget() const
{
	return m_rootWidget;
}
