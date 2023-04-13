#ifndef INDEXER_H
#define INDEXER_H

#include <string.h>

#include "Constants_Robot.h"
#include "Includes.h"
#include "motor.h"
// Testing class, here will be added all the functions for testing phase
class Indexer_Test {
 private:
#pragma region Indexer Variables
  std::map<int, std::string> shapes{{0, "Empty"}, {1, "Cone"}, {2, "Cube"}};
  // Spindexer_Intake_Motor
  Motor motor{
      Spindexer_Motor_Can_Id,       Spindexer_Motor_Type,
      Spindexer_Motor_Max_Speed,    Spindexer_Motor_Acceleration,
      Spindexer_Motor_Deceleration, Spindexer_Motor_Inverted,
  };

  frc::PS4Controller *joystick= new frc::PS4Controller(kOperatorJoystickPort);
#pragma endregion

#pragma region Class Methods
  void run_motor(double speed);
#pragma endregion
 public:
  // Functions and constructors definition
  Indexer_Test();
  void init();
  //void run(int networkTableColorValue);
  void run();
};

// Teleop class, here will be added all the functions for the teleop and auto
// phase
class Indexer : public Indexer_Test {
 private:
  // Variables and motors/pneumatics objects as arguments here
 public:
  // Functions and constructors definition
  Indexer();
};

#endif