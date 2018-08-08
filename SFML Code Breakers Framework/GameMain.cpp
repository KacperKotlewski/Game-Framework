#include "GameMain.h"



Game::Game(unsigned int witdh, unsigned int height, std::string windowName, int tick)
	:
	m_wnd( { witdh, height }, windowName ),
	m_tick(Ticks(tick))
{
}


Game::~Game()
{
}


void Game::Run()
{
	// Start the game loop
	while (m_wnd.isOpen())
	{
		// Process events
		sf::Event event;
		while (m_wnd.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				m_wnd.close();
		}

		//update ticks
		m_tick.Update();

		// Update FPS
		m_FPScounter.Update();
		if (m_FPScounter.IsChanged())
		{
			std::cout << "Fps: " << m_FPScounter.GetValue() << std::endl;
		}

		// Clear screen
		m_wnd.clear();

		// Update logic elements
		m_ygame.m_LogicUpdate(m_tick.getElapsed());
		//check lost tick
		while (m_tick.tickCount > 0) { m_ygame.m_FixedUpdate(m_tick.getElapsed()); m_tick.tickCount--; }
		// Draw the sprite
		m_ygame.m_FrameUpdate(m_wnd);

		// Display textures on window
		m_wnd.display();
	}
}