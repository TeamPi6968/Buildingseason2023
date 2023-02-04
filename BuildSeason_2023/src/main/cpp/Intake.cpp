#include "Intake.h"

#pragma region Test Intake functions

Intake_Test::Intake_Test()
{
}

void Intake_Test::actuate_cylinder(frc::DoubleSolenoid cylinder, bool actuate)
{
    if (actuate)
    {
        cylinder.Set(frc::DoubleSolenoid::Value::kForward);
    }
    else
    {
        cylinder.Set(frc::DoubleSolenoid::Value::kReverse);
    }
}

#pragma endregion

#pragma region Intake functions

Intake::Intake() : Intake_Test()
{
}

#pragma endregion
