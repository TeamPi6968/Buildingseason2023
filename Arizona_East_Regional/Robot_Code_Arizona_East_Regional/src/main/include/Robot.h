// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ROBOT_H
#define ROBOT_H

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include "RobotContainer.h"

// These includes are needed for the Network table
#include <rev/AbsoluteEncoder.h>
#include <rev/CANSparkMax.h>

#include "Constants_Robot.h"
#include "Indexer.h"
#include "Intake.h"
#include "Outtake.h"
#include "Pneumatics.h"
#include "motor.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <cameraserver/CameraServer.h>
#include <frc/Timer.h>

class Robot : public frc::TimedRobot {
 public:
  // Get the Networktable Entry (in this case entries from Jetson)
  // xEntry and yEntry can be changed with any value which you would
  // like to get from jetson for example distance.
  frc::Timer time{};
  units::second_t delayIntakeAuto{2}; //timer of two seconds

  nt::NetworkTableEntry xEntry;
  nt::NetworkTableEntry yEntry;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  AHRS gyro{frc::SPI::kMXP};

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;

  RobotContainer m_container;

  frc::PS4Controller joystick_{kOperatorJoystickPort};

  // variable
  bool dissableCompressor = false;
  // define compressor with its canID, and type
  frc::Compressor Compressor_Robot2023{Pneumatic_Can_Id,
                                       frc::PneumaticsModuleType::REVPH};

//Defining subsystems objects
  Intake intake{};
  Indexer indexer{};
  Outtake outtake{};


  //Motor TestMotor{
  //    Test_Intake_Motor_Can_Id,       Test_Intake_Motor_Type,
  //    Test_Intake_Motor_Max_Speed,    Test_Intake_Motor_Acceleration,
   //   Test_Intake_Motor_Deceleration, Test_Intake_Motor_Inverted,
  //};
};
#endif