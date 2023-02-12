#ifndef INCLUDES_H
#define INCLUDES_H

// In this file all the includes will be written

#pragma region General
#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>
#include <optional>
#include "Constants.h"
#pragma endregion

#pragma region Motors
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#pragma endregion

#pragma region Pneumatics
#include <frc/PneumaticsControlModule.h>
#include <frc/DoubleSolenoid.h>
#pragma endregion

#pragma region Servos

#pragma endregion

#pragma region Sensors

#pragma endregion

#pragma region Swerve
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/SwerveModulePosition.h>
#include <frc/kinematics/SwerveModuleState.h>
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxAbsoluteEncoder.h>
#include <rev/SparkMaxPIDController.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include <frc/ADIS16470_IMU.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/kinematics/SwerveDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "AHRS.h"
#pragma endregion

#endif