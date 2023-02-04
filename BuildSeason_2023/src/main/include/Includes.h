#ifndef INCLUDES_H
#define INCLUDES_H

// In this file all the includes will be written

#pragma region General
#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include "Robot.h"
#include "RobotContainer.h"

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

#pragma region Systems
#include "Swerve.h"
#include "Intake.h"
#include "Indexer.h"
#include "Outtake.h"
#pragma endregion

#pragma region Controllers
#include <frc/PS4Controller.h>
#include <frc/XboxController.h>
#pragma endregion

#endif