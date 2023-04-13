// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/Filesystem.h>
#include <frc/controller/PIDController.h>
#include <frc/geometry/Translation2d.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <units/angle.h>
#include <units/velocity.h>
#include <wpi/fs.h>

#include <utility>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  // The left stick controls translation of the robot.
  // Turning is controlled by the X axis of the right stick.
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        static double heading = m_drive.GetAngle();

        // chage heading towards the intake [Circle button]
        if (m_driverController.GetCrossButtonPressed()) {
          heading = -m_drive.GetAngle();
        }

        std::pair<double, double> JoystickInput = m_drive.FOV_joystick(
            m_driverController.GetLeftX(), m_driverController.GetLeftY(),
            heading, -m_drive.GetAngle());

        m_drive.Drive(-units::meters_per_second_t{frc::ApplyDeadband(
                          JoystickInput.second, 0.06)},
                      -units::meters_per_second_t{
                          frc::ApplyDeadband(JoystickInput.first, 0.06)},
                      -units::radians_per_second_t{frc::ApplyDeadband(
                          m_driverController.GetRawAxis(4), 0.06)},
                      false);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhileTrue(new frc2::RunCommand([this] { m_drive.SetX(); }, {&m_drive}));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Set up config for trajectory
   //frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,
   //AutoConstants::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
   //config.SetKinematics(m_drive.kDriveKinematics);

  //   // An example trajectory to follow.  All units in meters.
   //auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
  // Start at the origin facing the +X direction
  // frc::Pose2d{0_m, 0_m, 0_deg},
  // Pass through these two interior waypoints, making an 's' curve path
  //{frc::Translation2d{1_m, 0_m}, frc::Translation2d{1_m, 0_m}},
  //{frc::Translation2d{2_m, 0_m}},
  // End 3 meters straight ahead of where we started, facing forward
  // frc::Pose2d{2_m, 0_m, 0_deg},
  // Pass the config
  // config);
  // Start at the origin defined by the user, field oriented
  // frc::Pose2d{0_m, 0_m, 0_deg};

  // Load the file where the path is saved which is generated with pathweaver
  // Make sure that the path which you have generated is in deploy folder
  // fs::path deployDirectory = frc::filesystem::GetDeployDirectory();
  // deployDirectory = deployDirectory / "paths" / "lalala.wpilib.json";

  // Create the trajectory using the pathplanning file.
  // frc::Trajectory AutoTrajectory =
  // frc::TrajectoryUtil::FromPathweaverJson(deployDirectory.string());

  // frc::ProfiledPIDController<units::radians> thetaController{
  //     AutoConstants::kPThetaController, 0, 0,
  //     AutoConstants::kThetaControllerConstraints};

  // thetaController.EnableContinuousInput(units::radian_t{-std::numbers::pi},
  //                                      units::radian_t{std::numbers::pi});

  // frc2::SwerveControllerCommand<4> swerveControllerCommand(
  // exampleTrajectory, [this]() { return m_drive.GetPose(); },

  // m_drive.kDriveKinematics,

  // frc2::PIDController{AutoConstants::kPXController, 0, 0},
  // frc2::PIDController{AutoConstants::kPYController, 0, 0}, thetaController,

  //[this](auto moduleStates) { m_drive.SetModuleStates(moduleStates); },

  //{&m_drive});

  // Reset odometry to the starting pose of the trajectory.
  // m_drive.ResetOdometry(exampleTrajectory.InitialPose());

  // no auto
  // return new frc2::SequentialCommandGroup(
  //     std::move(swerveControllerCommand),
  //     frc2::InstantCommand(
  //         //[this]() { m_drive.Drive(0.02_mps, 0.02_mps, 0.02_rad_per_s,
  //         false); }, {}));
  //           [this]() { m_drive.Drive(0_mps, 0_mps, 0_rad_per_s, false); },
  //           {}));
  bool init = 0;
  if(init == 0){
    timeDrive.Reset();
    timeDrive.Start();
    init = 1;
  }
 // frc::SmartDashboard::PutNumber("timedrive", )
if(timeDrive.Get() > delayDrive){
  return new frc2::FunctionalCommand(
      // // Reset odometry on command start
      // //bool interrupted;
       [this] {m_drive.ResetOdometry(frc::Pose2d{0_m, 0_m, 0_deg}); },
      // // drive while the command is executing
       [this]{ m_drive.Drive(0_mps, 0_mps, 0_rad_per_s, false); },
      // // stop driving
       [this](bool interrupted) { m_drive.Drive(0_mps, 0_mps, 0_rad_per_s, false);},      
       [this] {
         frc::SmartDashboard::PutNumber("distance", m_drive.GetPose().X().value());
         return m_drive.GetPose().X() <= -2_m;},
       {&m_drive});
      
          // Reset odometry on command start
      // [this] {m_drive.ResetOdometry(frc::Pose2d{0_m, 0_m, 0_deg}); },
      // // drive while the command is executing
      // //[this]{ m_drive.Drive(0.02_mps, 0_mps, 0_rad_per_s, false); },
      // [this]{m_drive.Drive(0.02_m, 0_mps, 0_rad_per_s, false);},
      // // stop driving
      // [this](bool interrupted) { m_drive.Drive(0_mps, 0_mps, 0_rad_per_s, false);},      
      // [this] {
      //   frc::SmartDashboard::PutNumber("distance", m_drive.GetPose().X().value());
      //   return m_drive.GetPose().X() <= -2_m;},
      // {&m_drive});
}
}
