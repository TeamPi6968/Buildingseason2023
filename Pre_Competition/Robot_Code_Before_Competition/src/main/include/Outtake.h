#ifndef OUTTAKE_H
#define OUTTAKE_H

#include <rev/AbsoluteEncoder.h>
#include <rev/CANSparkMax.h>
#include <string.h>

#include "Constants_Robot.h"
#include "Includes.h"
#include "Pneumatics.h"
#include "motor.h"
 
//#include "frc/buttons/POVButton.h"
// Testing class, here will be added all the functions for testing phase
class Outtake_Test {
 private:
  using bool_func = bool (*)();
#pragma region Outtake Class Variables

  // Left_Lift_Motor
  Motor liftLeftMotor{
      Lift_Left_Motor_Can_Id,       Lift_Left_Motor_Type,
      Lift_Left_Motor_Max_Speed,    Lift_Left_Motor_Acceleration,
      Lift_Left_Motor_Deceleration, Lift_Left_Motor_Inverted,
  };

  // Right_Lift_Motor
  Motor liftRightMotor{
      Lift_Right_Motor_Can_Id,       Lift_Right_Motor_Type,
      Lift_Right_Motor_Max_Speed,    Lift_Right_Motor_Acceleration,
      Lift_Right_Motor_Deceleration, Lift_Right_Motor_Inverted,
  };

  // Arm_Motor
  Motor armMotor{
      Arm_Motor_Can_Id,       Arm_Motor_Type,         Arm_Motor_Max_Speed,
      Arm_Motor_Acceleration, Arm_Motor_Deceleration, Arm_Motor_Inverted,
  };

    // Gripper_Motor
  Motor gripperMotor{
      Gripper_Motor_Can_Id,       Gripper_Motor_Type,         Gripper_Motor_Max_Speed,
      Gripper_Motor_Acceleration, Gripper_Motor_Deceleration, Gripper_Motor_Inverted,
  };

  // Gripper solenoid
  frc::DoubleSolenoid gripperSolenoid{
      Pneumatic_Can_Id, frc::PneumaticsModuleType::REVPH,
      Gripper_Pneumatic_Channel_1, Gripper_Pneumatic_Channel_2};

  // Controllers
  frc::PS4Controller *joystick = new frc::PS4Controller(kOperatorJoystickPort);
  //frc::PS4Controller *Driverjoystick = new frc::PS4Controller(kDriversJoystickPort);

  // Encoders
  rev::SparkMaxAbsoluteEncoder encoder_lift{
      liftLeftMotor.GetSpark().GetAbsoluteEncoder(
          rev::SparkMaxAbsoluteEncoder::Type::kDutyCycle)};

  rev::SparkMaxAlternateEncoder encoder_arm{
      armMotor.GetSpark().GetAlternateEncoder(
          rev::CANEncoder::AlternateEncoderType::kQuadrature, 8192)};

  // PID Controllers
  frc::PIDController *liftPID =
      new frc::PIDController(kP_Lift, kI_Lift, kD_Lift);
  frc::PIDController *liftPIDAuto = new frc::PIDController(kP_Lift_Auto, kI_Lift_Auto, kD_Lift_Auto);
  frc::PIDController *armPID = new frc::PIDController(kP_Arm, kI_Arm, kD_Arm);

  enum iterators {
    Indexer_Position,
    Home_Position,
    Ground_Position,
    Mid_Position,
    Loading_Position,//dit overbruggen voor test
    High_Position,
    Idle
  };

#pragma endregion

#pragma region Class Methods
  double getLiftPosition();
  double getArmPosition();
  double normalization(double value, double min_value, double max_value,
                       double min_range, double max_range);

  unsigned char getPositionButton();
  void setZeroPosition();
  void armToPosition(double &current_position, double target_position);
  void liftToPosition(double &current_angle, double target_angle,
                      bool follow_motor_inverted);
  void togglePositions(bool toggle_positions[]);
  void counterPositions(unsigned char &counter, bool forward_position_button,
                        bool backward_position_button,
                        bool home_position_button);
  std::pair<double, double> positionSelection(bool toggle_positions[],
                                              bool &start_moving);
  std::pair<double, double> positionSelection(int counter, bool &start_moving);
  void runToPosition();
  void runToPositionAuto();
  void gripperAcutation();
  void gripperActuationAuto();
  void tunePID(double liftConstants[], double armConstants[]);
  void runActiveGripper();
#pragma endregion

 public:
  // Functions and constructors definition
  Outtake_Test();
  void init();
  void run();
  void autonomous();
};

// Teleop class, here will be added all the functions for the teleop and auto
// phase
class Outtake : public Outtake_Test {
 private:
  // Variables and motors/pneumatics objects as arguments here
 public:
  // Functions and constructors definition
  Outtake();
};

#endif