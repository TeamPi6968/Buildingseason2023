#ifndef INCLUDES_H
#define INCLUDES_H

// In this file all the includes will be written

#pragma region General
#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include <optional>
#pragma endregion

#pragma region Motors
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#pragma endregion

#pragma region Pneumatics
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/Solenoid.h>
#pragma endregion

#pragma region Controllers
#include <frc/Joystick.h>
#include <frc/PS4Controller.h>
#include <frc/XboxController.h>
#pragma endregion

#pragma region Network Tables
// These includes are needed for the Network table
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#pragma endregion

#pragma region Swerve
#include <frc/ADIS16470_IMU.h>
#include <frc/Compressor.h>
#include <frc/controller/PIDController.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxAbsoluteEncoder.h>
#include <rev/SparkMaxPIDController.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/velocity.h>

#include <utility>

#include "AHRS.h"
#pragma endregion

#endif