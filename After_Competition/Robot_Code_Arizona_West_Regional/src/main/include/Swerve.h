#ifndef SWERVE_H
#define SWERVE_H

#include "Includes.h"
#include "subsystems/DriveSubsystem.h"
// Teleop class, here will be added all the functions for the teleop and auto phase
class Swerve
{
private:
   //DriveSubsystem m_Drive;
public:
    // Functions and constructors definition
    Swerve();
    //void run(frc::PS4Controller Joystick);
};

// Testing class, here will be added all the functions for testing phase
class Swerve_Test : public Swerve
{

private:
public:
    // Functions and constructors definition
    Swerve_Test();
};

#endif