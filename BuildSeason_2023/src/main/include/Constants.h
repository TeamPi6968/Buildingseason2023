// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#pragma region Pneumatics Variables
const auto forward = frc::DoubleSolenoid::Value::kForward;//cylinder forward state
const auto reverse = frc::DoubleSolenoid::Value::kReverse;//cylinder reverse state
const auto revPneumatics= frc::PneumaticsModuleType::REVPH;//rev pneumatics control module
const auto ctrePneumatics= frc::PneumaticsModuleType::CTREPCM;//rev pneumatics control module
#pragma endregion


#pragma region Intake Variables
int leftCylinderForwardID= 0;
int leftCylinderReverseID= 1;
int RightCylinderForwardID= 2;
int RightCylinderReverseID= 3;
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
