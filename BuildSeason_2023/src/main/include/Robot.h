// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#ifndef ROBOT_H
#define ROBOT_H

#include "Includes.h"

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

  Intake_Test *intake;
  Intake *intake2;

private:
  // Have it empty by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  std::optional<frc2::CommandPtr> m_autonomousCommand;
  // frc::XboxController *Joystick1 = new frc::XboxController(0);
  RobotContainer *m_container;
};

#endif