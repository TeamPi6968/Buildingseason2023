#ifndef INTAKE_H
#define INTAKE_H

#include "Includes.h"

// Testing class, here will be added all the functions for testing phase
class Intake_Test
{
private:
    frc::DoubleSolenoid CylinderLeft{frc::PneumaticsModuleType::REVPH, leftIntakeCylinderForwardID, leftIntakeCylinderReverseID};
    frc::DoubleSolenoid CylinderRight{frc::PneumaticsModuleType::REVPH, rightIntakeCylinderForwardID, rightIntakeCylinderReverseID};

public:
    // Functions and constructors definition
    Intake_Test();

    void control_cylinders_hold(bool button); // actuating cylinder while button is pressed
    void control_cylinders_toggle(bool button); // toggle the states of the cylinder when button is pressed
};

// Teleop class, here will be added all the functions for the teleop and auto phase
class Intake : public Intake_Test
{
private:
    // Variables and motors/pneumatics objects as arguments here

public:
    // Functions and constructors definition
    Intake();
};

#endif