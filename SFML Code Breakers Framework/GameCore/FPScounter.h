#pragma once
#include <SFML/Graphics.hpp>

#include "DeltaTime.h"

class FPScounter
{
public:
	FPScounter();
	~FPScounter();

	void Update();
	int GetValue();
	bool IsChanged();

private:
	sf::Clock m_fpsTimer;
	DeltaTime m_delayTimer;

	float m_fps = 0;

	int m_fps_last = 0;

	int m_frameCount = 0;

	bool m_changed = false;
};