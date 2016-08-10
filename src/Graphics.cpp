#include "Graphics.h"

#include <SFML/OpenGL.hpp>

Graphics::Graphics() :
	m_screenWidth(480),
	m_screenHeight(480),
	m_window()
{}

Graphics::~Graphics()
{}

void Graphics::initWindow()
{
	m_window.create(sf::VideoMode(m_screenWidth, m_screenHeight), "Tic-tac-toe");
	m_window.setVerticalSyncEnabled(true);
	m_window.setActive(true);
}

void Graphics::initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glViewport(0, 0, m_screenWidth, m_screenHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void Graphics::init()
{
	initWindow();
	initGL();
}

void Graphics::beginScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// (0, 0) is the top left corner
	glOrtho(
		0.0,
		static_cast<double>(m_screenWidth),
		static_cast<double>(m_screenHeight),
		0.0,
		-1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Graphics::endScene()
{
	m_window.display();
}

void Graphics::onResize(unsigned width, unsigned height)
{
	width = (width < 1) ? 1 : width;
	height = (height < 1) ? 1 : height;
/*
	if (width < 1 ||
		height < 1)
	{
		// Nope, this is not an exceptional case
		//throw std::runtime_error("")
		// Simply return values to their bounds
	}
*/
	m_screenWidth = width;
	m_screenHeight = height;
}

sf::RenderWindow& Graphics::getWindow()
{
	return m_window;
}
