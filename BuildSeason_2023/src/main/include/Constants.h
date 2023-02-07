// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef CONSTANTS_H
#define CONSTANTS_H

#pragma region Pneumatics Variables


#pragma endregion

#pragma region Intake Variables
static int leftIntakeCylinderForwardID = 0;
static int leftIntakeCylinderReverseID = 1;
static int rightIntakeCylinderForwardID = 2;
static int rightIntakeCylinderReverseID = 3;
const int kJoystickPort = 0;
const int kLeftMotorPort = 1;
const int kRightMotorPort = 2;
const int kSquareButton = 1;
#pragma endregion

#pragma region Indexer Variables
static int leftIndexerCylinderForwardID = 4;
static int leftIndexerCylinderReverseID = 5;
static int rightIndexerCylinderForwardID = 6;
static int rightIndexerCylinderReverseID = 7;
#pragma endregion


/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants
{

    constexpr int kDriverControllerPort = 0;

} // namespace OperatorConstants

#endif