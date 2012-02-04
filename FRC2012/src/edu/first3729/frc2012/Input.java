package edu.first3729.frc2012;

import edu.wpi.first.wpilibj.*;

public class Input {

	private Joystick _joy_left;
	private Joystick _joy_right;
	private Joystick _controller;
	
	// Set to differentiate between drive modes.
	// m = mecanum
	// a = arcade
	// t = tank
	protected char mode = 'm';
        private int booleanInputs = 0;
	
	public Input()
	{
		this._joy_left = new Joystick(1);
		this._joy_right = new Joystick(2);
		this._controller = new Joystick(3);
	}
	
	public void setMode(char m)
	{
		this.mode = m;
	}
        
        public boolean checkButton(int joystick, int button_id)
        { 
            switch (joystick) {
                case 0:
                    return this._joy_left.getRawButton(button_id);
                case 1:
                    return this._joy_right.getRawButton(button_id);
                case 2:
                    return this._controller.getRawButton(button_id);
                default:
                    return checkButton(2, button_id);
            }
        }
	
	public char getMode() { return mode; } 
	
	public double getX()
	{
		switch(mode)
		{
		case 'm':
			return normalize(this._joy_right.getRawAxis(1), -1.0, 1.0);
		case 'a':
			return expo(normalize(this._joy_left.getX(), Params.XMIN, Params.XMAX), Params.XEXPO);
		case 't':
			return expo(normalize(this._joy_left.getY(), -1.0, 1.0), Params.JOYEXPO);
                case 'l':
                        return 0;
                default:
			mode = 'l';
			return getX();
		}
	}
	
	public double getY()
	{
		switch(mode)
		{
		case 'm':
			return normalize(-this._joy_left.getRawAxis(2), -1.0, 1.0);
		case 'a':
			return expo(normalize(this._joy_left.getY(), Params.YMIN, Params.YMAX) * -1.0, Params.YEXPO);
		case 't':
			return expo(normalize(this._joy_right.getY(), -1.0, 1.0), Params.JOYEXPO);
                case 'l':
                        return 0;
                default:
			mode = 'l';
			return getY();
		}
	}
	
	public double getZ()
	{
		switch(mode)
		{
		case 'm':
			return normalize(this._joy_left.getRawAxis(1), -1.0, 1.0);
		case 'a':
			return 0;
		case 't':
			return 0;
                case 'l':
                        return 0;
		default:
			mode = 'l';
			return getZ();
		}
	}
        
        public int getBooleanButtonInputs(int side)
        {
            int i;
            switch (side)
            {
            case 0:
                for (i = 1; i <= 11; i++)
                {
                    this.booleanInputs ^= toInt(this._joy_left.getRawButton(i)) << (i - 1);
                }
                break;
            case 1:
                for (i = 1; i <= 11; i++)
                {
                    this.booleanInputs ^= toInt(this._joy_right.getRawButton(i)) << (i - 1);
                }
                break;
            default:
                return getBooleanButtonInputs(0);
            }
            return this.booleanInputs;
        }
        
        private int toInt(boolean thingummy)
        {
            if (thingummy)
                return 1;
            else
                return 0;
        }
	
	/**
	 * @brief Exponential function that makes the controller more sensitive toward the center and less so toward the outside
	 * 
	 * @author Adam Bryant
	 * @param x Input to be expo-ed
	 * @param a Pre-defined exponentiation factor
	 * @return The expo-ed value
	 */
	private double expo(double x, double a)
	{
		return (a * (x * x * x) + (1 - a) * x);
	}
	
	/**
	 * @brief Normalize input between -1.0 and 1.0.  Also take into account min and max values given by controller.
	 *
	 * @author Adam Bryant
	 * @param joyVal Input value to be normalized
	 * @param min Minimum controller value.  If using a joystick, supply -1.0.
	 * @param max Maximum controller value.  If using a joystick, supply 1.0.
	 * @return The normalized value
	 */
	private double normalize(double joyVal, double min, double max)
	{
		double retVal = 0.0;
		if (joyVal < 0.0)
			retVal = Math.abs(joyVal) / min;
		else if (joyVal > 0.0)
			retVal = Math.abs(joyVal) / max;
		if (retVal < -1.0)
			retVal = -1.0;
		else if (retVal > 1.0)
			retVal = 1.0;
		return retVal;
	}
}
