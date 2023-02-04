#include "Intake.h"

#pragma region Test Intake functions

Intake_Test::Intake_Test()
{
}

void Intake_Test::control_cylinders_hold(bool button)
{
    if (button)
    {
        CylinderLeft.Set(frc::DoubleSolenoid::Value::kForward);
        CylinderRight.Set(frc::DoubleSolenoid::Value::kForward);
    }
    else
    {
        CylinderLeft.Set(frc::DoubleSolenoid::Value::kReverse);
        CylinderRight.Set(frc::DoubleSolenoid::Value::kReverse);
    }
}

void Intake_Test::control_cylinders_toggle(bool button)
{
    frc::Debouncer debounce_button{125_ms};
    
    if (debounce_button.Calculate(button))
    {
       CylinderLeft.Toggle();
       CylinderRight.Toggle();
    }
}

#pragma endregion

#pragma region Intake functions

Intake::Intake() : Intake_Test()
{
}

#pragma endregion
