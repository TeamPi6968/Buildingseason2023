#ifndef INTAKE_H
#define INTAKE_H

#include "Includes.h"

// Testing class, here will be added all the functions for testing phase
class Intake_Test
{
private:
    frc::DoubleSolenoid CylinderLeft{frc::PneumaticsModuleType::REVPH, leftCylinderForwardID, leftCylinderReverseID};
    frc::DoubleSolenoid CylinderRight{frc::PneumaticsModuleType::REVPH, RightCylinderForwardID, RightCylinderReverseID};

public:
    // Functions and constructors definition
    Intake_Test();

    void actuate_cylinder(frc::DoubleSolenoid cylinder, bool actuate);
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