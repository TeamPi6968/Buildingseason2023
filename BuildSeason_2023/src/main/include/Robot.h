// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#ifndef ROBOT_H
#define ROBOT_H

#include "Includes.h"
#include <frc/PS4Controller.h>

#pragma region Forward class definitions
class Intake_Test;
class Intake;
class Indexer_Test;
class Indexer;
class Outtake_Test;
class Outtake;
class Swerve;
class Swerve_test;
class RobotContainer;
#pragma endregion

class Robot : public frc::TimedRobot
{
public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;



private:
  // Have it empty by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  std::optional<frc2::CommandPtr> m_autonomousCommand;
  frc::PS4Controller *Joystick1{0};
  RobotContainer *m_container;
  Intake_Test *intake;
};

#endif