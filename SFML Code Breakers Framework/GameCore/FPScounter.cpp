
#include "FPScounter.h"

FPScounter::FPScounter()
{
}

FPScounter::~FPScounter()
{
}

void FPScounter::Update()
{
	m_frameCount++;

	//check delay of time (0.5 sec)
	if (m_delayTimer.CheckDelay(0.5))
	{
		int temp = int(m_fps);
		

		m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
		m_frameCount = 0;
		m_delayTimer.Update(); 

		if (temp != int(m_fps))
		{
			m_fps_last = int(m_fps);
			m_changed = true;
		};
	}
}

int FPScounter::GetValue()
{
	//get fps
	return int(m_fps);
}

bool FPScounter::IsChanged()
{
	if (m_changed) { m_changed = false; return true; }
	return false;
}
