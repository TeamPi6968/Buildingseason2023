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