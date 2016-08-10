#pragma once

class Game;
class Widget;

class Interface
{
public:
	Interface(Game* game);
	~Interface();

	void init();
	void tick(double deltaTime);
	void draw();

	Widget* getRootWidget() const;
private:
	Game* m_game;
	Widget* m_rootWidget;
};
