/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.first3729.frc2012.input;

import edu.first3729.frc2012.utility.FRCUtility;
import edu.wpi.first.wpilibj.Joystick;

/**
 *
 * @author matthewhaney
 */
public class FRCInputXbox extends FRCInput {
    
    public FRCInputXbox(int number) {
        super(number);
    }
    
    public static final int A_BUTTON = 1;
    public static final int B_BUTTON = 2;
    public static final int X_BUTTON = 3;
    public static final int Y_BUTTON = 4;
    public static final int L_BUTTON = 5;
    public static final int R_BUTTON = 6;
    public static final int BACK_BUTTON = 7;
    public static final int START_BUTTON = 8;
    public static final int L3_BUTTON = 9;
    public static final int R3_BUTTON = 10;
    public static final int LEFT_TRIGGER = 77;
    public static final int RIGHT_TRIGGER = 78;
    public static final int LEFT_STICK_X = Joystick.AxisType.kX.value;
    public static final int LEFT_STICK_Y = Joystick.AxisType.kY.value;
    public static final int TRIGGER_AXIS = Joystick.AxisType.kZ.value;
    
    public double get_triggers() {
        return this.get_z();
    }
    
    public boolean get_button(int id) {
        return this._joy.getRawButton(id);
    }
    
}
