/*
 RJFRC - The code used by Regis Jesuit High School's FIRST Robotics Competition team #3729 over the years, starting from 2011 (rookie year).
 Copyright (C) 2011 Regis Jesuit High School
 
 This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 \file Teleoperated.cpp
 \brief File containing definitions of functions declared in class \a Teleoperated (declared in Teleoperated.h).
 \authors Matthew Haney, Drew Lazzeri
 */

#include "Teleoperated.h"
using namespace RJFRC2011;

/*!
 \brief Construct from the addresses of a drive system, a manipulator, a controller, and the driver station LCD screen.
 \details Set up pointers to passed adresses.  Initialize state and condition pointers.
 */
RJFRC2011::Teleoperated::Teleoperated(Drive * drive, Manipulator * manip, Controller * controller, DriverStationLCD * screen)
{
	this->_drive = drive;
	this->_manip = manip;
	this->top = this->_manip->GetTopLimitSwitchAddress();
	this->bottom = this->_manip->GetBottomLimitSwitchAddress();
	this->_controller = controller;
	this->_screen = screen;
	this->minibotShelf = new Relay(MINIBOT_SHELF_RELAY_PORT, Relay::kBothDirections);	
}

//! Destructor.  Kill stuff.
RJFRC2011::Teleoperated::~Teleoperated()
{
	delete minibotShelf;
}

/*!
 \brief Set up for Teleoperated mode.
 */
void RJFRC2011::Teleoperated::Init()					// state 0
{
	manipulatorElevation = driveSpeed = driveTurn;
	manipulatorAction = 0;
	minibotSwitches = 0;
	_nextState = 1;
}

/*!
 \brief This is where the magic happens.  Get driver input, then figure out what to do with it.
 \details Get input from the controller (see \a Controller class).  Based on this, decide what values to send to the \a Drive class and \a Manipulator class, as well as how to move the relay (\a Relay class) controlling the minibot deployment system.
 */
void RJFRC2011::Teleoperated::Go()
{
	// Get driver input
	manipulatorElevation = this->_controller->getManipulatorElevation();
	driveSpeed = this->_controller->getDriveSpeed();
	driveTurn = this->_controller->getDriveTurn();
	manipulatorAction = this->_controller->getManipulatorAction();
	minibotSwitches = this->_controller->getMinibotSwitches();
	
	// Move robot
	this->_drive->drive(driveSpeed, driveTurn);
	
	// Elevate manipulator
	if ((manipulatorElevation > 0.35) || (manipulatorElevation < -0.35))
		this->_manip->elevate(manipulatorElevation);
	else
		this->_manip->stopManipulatorElevation();
	this->_screen->PrintfLine(DriverStationLCD::kUser_Line3, topchar(manipulatorElevation));
	this->_screen->PrintfLine(DriverStationLCD::kUser_Line4, topchar(manipulatorAction));
	
	// Input tube
	if (manipulatorAction == 3)
	{
		this->_manip->inputTube();
	}
	else if (manipulatorAction == 0)
	{
		this->_manip->stopManipulatorAction();
	}
	
	// Rotate tube
	if (manipulatorAction == 2)
	{
		this->_manip->rotateTube();
	}
	
	// Eject tube
	if (manipulatorAction == 1)
		this->_manip->ejectTube();
	
	// Move minibot
	if (minibotSwitches == 2)						// 10
	{
		minibotShelf->Set(Relay::kForward);
	}
	else if (minibotSwitches == 1)					// 01
	{
		minibotShelf->Set(Relay::kReverse);
	}
	else if (minibotSwitches == 0)					// 00
	{
		minibotShelf->Set(Relay::kOff);
	}
	else//if (minibotSwitches == 3)					// 11
	{
		minibotShelf->Set(Relay::kOff);
	}
}

//! Print the values we're getting from the limit switches to the screen.
void RJFRC2011::Teleoperated::testLimitSwitches()
{
	if (top->Get() == 1)
	{
		this->_screen->PrintfLine(DriverStationLCD::kUser_Line3, "1");
	}
	else if (top->Get() == 0)
	{
		this->_screen->PrintfLine(DriverStationLCD::kUser_Line3, "0");
	}
	if (bottom->Get() == 1)
	{
		this->_screen->PrintfLine(DriverStationLCD::kUser_Line4, "1");
	}
	else if (bottom->Get() == 0)
	{
		this->_screen->PrintfLine(DriverStationLCD::kUser_Line4, "0");
	}
}
