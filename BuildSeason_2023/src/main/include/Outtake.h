#ifndef OUTTAKE_H
#define OUTTAKE_H

#include "Includes.h"

// Testing class, here will be added all the functions for testing phase
class Outtake_Test
{

private:
public:
    // Functions and constructors definition
    Outtake_Test();
    void init();
    void periodic();
    frc::PS4Controller controller{0};
    rev::CANSparkMax main_lift_motor{12,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax follow_lift_motor{9,rev::CANSparkMax::MotorType::kBrushless};
};

// Teleop class, here will be added all the functions for the teleop and auto phase
class Outtake : public Outtake_Test
{
private:
    // Variables and motors/pneumatics objects as arguments here
public:
    // Functions and constructors definition
    Outtake();
};

#endif