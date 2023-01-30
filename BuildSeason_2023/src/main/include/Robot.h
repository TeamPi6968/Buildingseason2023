// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include "RobotContainer.h"
#include <rev/CANSparkMax.h>
#include <frc/PS4Controller.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/controller/PIDController.h>
#include <frc/Timer.h>

class Robot : public frc::TimedRobot {
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

  RobotContainer m_container;
  
  // logic
  int State_Outtake;
  
  // Timer
  frc::Timer time{};
  units::second_t Time;//read the current time
  units::second_t Delay {2};//Delay time

  // Controller
  frc::PS4Controller controller{0};
  bool Button_outtake;
  
  // Motors
  int Can_id_motor_1;
  int Can_id_motor_2;
  int Can_id_extention;
  double speedLimiter_rotations;
  rev::CANSparkMax Motor_1{Can_id_motor_1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  double kP_1;
  double kI_1;
  double kD_1;
  double percent_speed;
  frc2::PIDController pid_1{kP_1, kI_1, kD_1};
  double current_angle;
  double target_angle;
  int start_angle;
  rev::CANSparkMax Motor_2{Can_id_motor_2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax Motor_Extension{Can_id_extention, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  // Don't know if this is the right encoder
  rev::SparkMaxAlternateEncoder Encoder_Motor_1{Motor_1.GetAlternateEncoder(rev::CANEncoder::AlternateEncoderType::kQuadrature, 4096)};
  
  // Pnuematics
  int Can_id_compressor;
  int Can_id_solenoid;
  int connection_1;
  int connection_2;
  frc::Compressor compressor{Can_id_compressor, frc::PneumaticsModuleType::REVPH};
  frc::DoubleSolenoid Solenoid{Can_id_solenoid, frc::PneumaticsModuleType::REVPH, connection_1, connection_2};
};
