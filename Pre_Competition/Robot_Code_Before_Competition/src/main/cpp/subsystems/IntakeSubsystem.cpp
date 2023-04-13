// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem() {
  // Implementation of subsystem constructor goes here.
}

frc2::CommandPtr IntakeSubsystem::IntakeMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

bool IntakeSubsystem::IntakeCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
  //when a user chosen button is pressed the intake will go forward and the wheels will turn at same speed
  /*if (joystick_.GetRawButtonPressed(Top_Intake_Joystick_Button))
  {
    Intake_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
    Top_Intake_Motor_.SetSpeed(Top_Intake_Motor_Max_Speed);
    Bottom_Intake_Motor_.SetSpeed(Bottom_Intake_Motor_Max_Speed);
    //Top_Intake_Motor_.SetSpeed(Bottom_Intake_Motor_.GetSpeed());
    
  }
  else if (joystick_.GetRawButtonReleased(Top_Intake_Joystick_Button))
  {
    Intake_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
    Top_Intake_Motor_.SetSpeed(0);
    Bottom_Intake_Motor_.SetSpeed(0);
    //Top_Intake_Motor_.SetSpeed(Bottom_Intake_Motor_.GetSpeed());
   // Top_Intake_Motor_.GetTalon().Follow(Bottom_Intake_Motor_.GetTalon());
  }*/

//double solenoid
  /*if(joystick_.GetRawButton(Intake_Pneumatic_Forward_Joystick)){
   Intake_doubleSolenoid.Set(frc::DoubleSolenoid::kForward);
  }else if (joystick_.GetRawButton(Intake_Pneumatic_Backward_Joystick)){
   Intake_doubleSolenoid.Set(frc::DoubleSolenoid::kReverse);
  }else{
   Intake_doubleSolenoid.Set(frc::DoubleSolenoid::kOff);
   frc::DoubleSolenoid::
  }*/
}

void IntakeSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
