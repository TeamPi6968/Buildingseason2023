// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() { /*terug zetten*/
  // compressor settings work pressure is 80_psi and system pressure is 120_psi
  // Compressor_Robot2023.Disable();

  Compressor_Robot2023.EnableAnalog(60_psi, 120_psi);
  if (dissableCompressor) Compressor_Robot2023.Disable();

  // Flush NetworkTables every loop. This ensures that robot pose and other
  // values are sent during every iteration.
  SetNetworkTablesFlushEnabled(true);

  // Get the values from the network table
  auto inst = nt::NetworkTableInstance::GetDefault();

  // Get value from datatable
  auto table = inst.GetTable("datatable");

  // Get x value from datatable
  xEntry = table->GetEntry("x");

  // Get y value from datatable
  yEntry = table->GetEntry("y");

  // 0 is spindexer en 1 is voorkant
  frc::CameraServer::StartAutomaticCapture(1);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

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

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }

  time.Reset();
  time.Start();
  //timeDrive.Reset();
  //timeDrive.Start();

  outtake.init();
 
 // m_drive.GetPose().X() = 0;
}

void Robot::AutonomousPeriodic() {
  // Write x en y value is smartdashboard (to test I put this here you can
  // use xEntry.GetValue() and yEntry.GetValue() where you would wish to use)
  frc::SmartDashboard::PutValue("X", xEntry.GetValue());
  frc::SmartDashboard::PutValue("Y", yEntry.GetValue());
  
  
  // if (time.Get() < delayIntakeAuto){
  //    intake.run_motors_auto();
  //  }

  //  else if (time.Get()> delayIntakeAuto){
  //    intake.stop_motors_auto();
  //  }
   // frc::SmartDashboard::PutNumber("timer", time.Get().value);
 if (time.Get() < delayOuttakeAuto){
  outtake.run_motors_auto(Speed_Arm_Retraction);
 }
 else if (time.Get() > delayOuttakeAuto && time.Get() < delayActivateGripperAuto){
  outtake.stop_motors_auto();
  outtake.runToPositionAuto(Mid_Angle);
 }
 if (time.Get() > delayActivateGripperAuto && time.Get()< delayDactivateGripperAuto){
  outtake.run_motors_auto(Speed_Arm_Extention);
 }
  //outtake.run_Gripper_Motor_Auto();
 if (time.Get() > delayDownArm && time.Get() < delayShoot){
  //frc::SmartDashboard::PutNumber("inside down", 1);
  outtake.runToPositionAuto(115);
  outtake.stop_motors_auto();
 }

 if (time.Get() > delayShoot && time.Get() < delayAutoStop){
  outtake.run_Gripper_Motor_Auto();
  outtake.run_motors_auto(Speed_Arm_Retraction);
 }

 if(time.Get() > delayAutoStop && time.Get() < delayhome){
  outtake.stop_Gripper_Motor_Auto();
  outtake.stop_motors_auto();
 }
 if(time.Get() > delayhome){
  outtake.runToPositionAuto(Home_Angle);
 }
 
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  // /*-----------terugzetten-------------------------------------*/
   // initialise intake
   intake.init();

  // /*------------------------------------------------*/
   // initialise indexer
    //indexer.init();

  // /*------------------------------------------------*/
   // initialise outtake
    outtake.init();
   //TestMotor.SetSpeed(Test_Intake_Motor_Max_Speed);
   
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  /*------------------------------------------------*/
  // Calling intake
  intake.run();

  /*------------------------------------------------*/
  // Calling indexer
  //indexer.run();

  /*------------------------------------------------*/
  // Calling outtake
  outtake.run();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
