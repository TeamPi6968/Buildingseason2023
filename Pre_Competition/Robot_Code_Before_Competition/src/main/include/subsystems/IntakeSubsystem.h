// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include "motor.h"
#include "Constants_Robot.h"
#include <frc/DoubleSolenoid.h>
#include <frc/Joystick.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Solenoid.h>
//#include "Pneumatics.h"

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  /**
   * Example command factory method.
   */
  frc2::CommandPtr IntakeMethodCommand();

  /**
   * An example method querying a boolean state of the subsystem (for example, a
   * digital sensor).
   *
   * @return value of some boolean subsystem state, such as a digital sensor.
   */
  bool IntakeCondition();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
// Joystick defination
  /*frc::Joystick joystick_{kOperatorJoystickPort};

  // Top_Intake_Motor
  Motor Top_Intake_Motor_{
      Top_Intake_Motor_Can_Id,
      Top_Intake_Motor_Type,
      Top_Intake_Motor_Max_Speed,
      Top_Intake_Motor_Acceleration,
      Top_Intake_Motor_Deceleration,
      Top_Intake_Motor_Inverted,
  };
  // Bottom_Intake_Motor
  Motor Bottom_Intake_Motor_{
      Bottom_Intake_Motor_Can_Id,
      Bottom_Intake_Motor_Type,
      Bottom_Intake_Motor_Max_Speed,
      Bottom_Intake_Motor_Acceleration,
      Bottom_Intake_Motor_Deceleration,
      Bottom_Intake_Motor_Inverted,
  };

  // Intake DoubleSolenoid can id, type, channel 1 and channel 2
  frc::DoubleSolenoid Intake_doubleSolenoid{Pneumatic_Can_Id,
                                            frc::PneumaticsModuleType::REVPH,
                                            Intake_Pneumatic_Channel_1,
                                            Intake_Pneumatic_Channel_2};*/
};

