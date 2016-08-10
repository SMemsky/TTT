#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Graphics
{
public:
	Graphics();
	~Graphics();

	void init();
	void beginScene();
	void endScene();

	void onResize(unsigned width, unsigned height);

	sf::RenderWindow& getWindow();
private:
	void initWindow();
	void initGL();
private:
	unsigned m_screenWidth = 480;
	unsigned m_screenHeight = 480;

	sf::RenderWindow m_window;
};
