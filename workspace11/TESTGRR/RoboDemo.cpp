#include "WPILib.h"

class RoboDemo : public SimpleRobot
{
public:
	RoboDemo(void)
	{
		Wait(8.0);
		AxisCamera & cam = AxisCamera::GetInstance();
	}
};

START_ROBOT_CLASS(RoboDemo);