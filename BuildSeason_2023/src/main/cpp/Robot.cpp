// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }

  // enable compressor (digital and analog added for now)
  compressor.EnableAnalog(100_psi, 120_psi); // Can't be higher then 120 psi
  //compressor.EnableDigital();

  // Read start value encoder
  current_angle = Encoder_Motor_1.GetPosition(); // value between 0 and 1

  // Follow function Motor 2 and set it inverted
  bool inverted = true;
  Motor_2.Follow(Motor_1, inverted);

  // Set PID
  pid_1.SetPID(kP_1, kI_1, kD_1);
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  // Read current encoder value
  current_angle = Encoder_Motor_1.GetPosition(); // value between 0 and 1
  switch (State_Outtake)
  {
    case 0:
      // Read button controller
      Button_outtake = controller.GetSquareButton(); 
      if(Button_outtake == true){
        // activate cylinder for gripper
        Solenoid.Set(frc::DoubleSolenoid::Value::kForward);
        State_Outtake = 1;
      }
      break;

    case 1:
      // move to desired position motor
      Motor_1.Set(speedLimiter_rotations * pid_1.Calculate(current_angle, target_angle));
      if(current_angle == target_angle){
        // Read current time
        
        State_Outtake = 2;
      }
      break;

    case 2:
      // Set extention
      Motor_Extension.Set(percent_speed);
      if(Time + Delay == true){
        // Deactivate cylinder for gripper
        Solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
        State_Outtake = 3;
      }
      break;

      case 3:
      // Move to start position
      Motor_1.Set(speedLimiter_rotations * pid_1.Calculate(current_angle, start_angle));
      if(encoder_value == start_angle){
        State_Outtake = 0;
      }
      break;
  
    default:
      break;
  }
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
