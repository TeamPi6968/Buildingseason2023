#ifndef INTAKE_H
#define INTAKE_H

#include "Constants_Robot.h"
#include "Includes.h"
#include "Pneumatics.h"
#include "motor.h"

#include <frc/filter/Debouncer.h>


// Testing class, here will be added all the functions for testing phase
class Intake_Test {
 private:
#pragma region Intake Class Variables

#pragma region Intake Actuators
  // Top_Motor
  Motor topMotor{
      Top_Intake_Motor_Can_Id,       Top_Intake_Motor_Type,
      Top_Intake_Motor_Max_Speed,    Top_Intake_Motor_Acceleration,
      Top_Intake_Motor_Deceleration, Top_Intake_Motor_Inverted,
  };

  // Bottom_Motor
  Motor bottomMotor{
      Bottom_Intake_Motor_Can_Id,       Bottom_Intake_Motor_Type,
      Bottom_Intake_Motor_Max_Speed,    Bottom_Intake_Motor_Acceleration,
      Bottom_Intake_Motor_Deceleration, Bottom_Intake_Motor_Inverted,
  };

  // Intake DoubleSolenoid can id, type, channel 1 and channel 2
  frc::DoubleSolenoid doubleSolenoid{
      Pneumatic_Can_Id, frc::PneumaticsModuleType::REVPH,
      Intake_Pneumatic_Channel_1, Intake_Pneumatic_Channel_2};

#pragma endregion

  frc::PS4Controller *joystick = new frc::PS4Controller(kOperatorJoystickPort);
  frc::PS4Controller *joystickdriver = new frc::PS4Controller(kDriversJoystickPort);

#pragma endregion

#pragma region Class Methods
  void
  actuate_pneumatics();  // Method for actuating the pneumatics of the Intake
  void run_motors(
      double topMotorSpeed,
      double bottomMotorSpeed);  // Method for running the Intake motors

#pragma endregion

 public:
  // Functions and constructors definition
  void init();  // Initialization Function
  void run();   //
  //void autonomous(); //
  void run_motors_auto();
  void stop_motors_auto();
  Intake_Test();
  
};

// Teleop class, here will be added all the functions for the teleop and auto
// phase
class Intake : public Intake_Test {
 private:
  // Variables and motors/pneumatics objects as arguments here

 public:
  // Functions and constructors definition
  Intake();
};

#endif