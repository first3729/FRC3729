/*
 RJFRC - The code used by Regis Jesuit High School's FIRST Robotics Competition team #3729 over the years, starting from 2011 (rookie year).
 Copyright (C) 2011 Regis Jesuit High School
 
 This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 \file macros.h
 \brief File containing a bunch of macros to de-clutter our other files.
 
 NOTE: All adjustment macros experimentally made by Adam Bryant.
 
 */

#ifndef _RJHS_FRC_2011_MACROS_H_
#define _RJHS_FRC_2011_MACROS_H_

#include <string>
#include <sstream>
using namespace std;

/*!
 \brief Convert an arbitrary type to a printable string, since this isn't Python
 \param val The number to be converted
 \returns The string representation of the passed number
 */

template <typename T>
const char * topchar(T val)
{
	ostringstream out_str("");
	out_str << val;
	return out_str.str().c_str();
}

// NOTICE: We've decided agianst the CAN network, as it would take a while to set up and we don't need those 4 extra PWM ports for anything else anyway.

// Adjustment macros by Adam Bryant
//! Adjustment for the fact that the joystick is slightly off-center
#define YCENTER (0.03125)
//! Adjustment for the fact that the joystick is slightly off-center
#define ROTCENTER (0.0156)
//! Minimum possible X value
#define XMIN -0.641
//! Maximum possible X value
#define XMAX 0.648
//! Minimum possible Y value
#define YMIN (-0.57-YCENTER)
//! Maximum possilble Y value
#define YMAX (0.641-YCENTER)
//! Minimum possible Z value
#define ZMIN (-0.54)
//! Maximum possible Z value
#define ZMAX (0.63)
//! Minimum possible rotation value
#define ROTMIN (-0.64-ROTCENTER)
//! Maximum possible rotation value
#define ROTMAX (0.68-ROTCENTER)
//! Exponential constant for modifying input from the x-axis
#define XEXPO 0.4
//! Exponential constant for modfying input from the y-axis
#define YEXPO 0.4
//! Exponential constant for modifying input form the rotational axis
#define ROTEXPO 0.6

// Port # constants: Digital I/O
//! Port # for the physical lane choosing switch in Autonomous
#define AUTONOMOUS_LANE_SWITCH_PORT 6
//! Port # for the physical fork choosing switch in Autonomous
#define AUTONOMOUS_FORK_SWITCH_PORT 7
//! Port # for the limit switch at the top of the manipulator elevator's reach
#define MANIPULATOR_ELEVATION_TOP_LIMIT_SWITCH_PORT	4
//! Port # for the limit switch at the bottom of the manipulator elevator's reach
#define MANIPULATOR_ELEVATION_BOTTOM_LIMIT_SWITCH_PORT 5
//! Port # of the leftmost line-following light sensor
#define LIGHT_SENSOR_LEFT_PORT 1
//! Port # of the center line-following light sensor
#define LIGHT_SENSOR_CENTER_PORT 2
//! Port # of the rightmost line-following light sensor
#define LIGHT_SENSOR_RIGHT_PORT	3

// Port # constants: Relays
//! Port # for the relay controlling the minbot shelf
#define MINIBOT_SHELF_RELAY_PORT 1
//! Port # for the relay controlling the top wheels of the manipulator
#define MANIPULATOR_TOP_RELAY_PORT 2
//! Port # for the relay controlling the bottom wheels of the manipulator
#define MANIPULATOR_BOTTOM_RELAY_PORT 3
//! Port # for the relay controlling elevation of the manipulator
#define MANIPULATOR_ELEVATION_RELAY_PORT 4

// Port # constants: PWM out
//! Port # of the front left Jaguar on the drive train
#define DRIVE_FRONT_LEFT_JAGUAR_PORT 5
//! Port # of the front right Jaguar on the drive train
#define DRIVE_FRONT_RIGHT_JAGUAR_PORT 7
//! Port # of the back left Jaguar on the drive train
#define DRIVE_BACK_LEFT_JAGUAR_PORT	6
//! Port # of the back right Jaguar on the drive train
#define DRIVE_BACK_RIGHT_JAGUAR_PORT 8

// Others
//! The default expiration time of the Watchdog timer, in seconds
#define DEFAULT_WATCHDOG_TIME 3.0
//! Speed at which we drive in Autonomous
#define AUTO_DRIVE_SPEED 0.35
//! Speed at which we turn in Autonomous
#define AUTO_TURN_SPEED 0.65
//! Speed at which we brake in Autonomous
#define AUTO_BRAKE_SPEED -0.6

#endif
