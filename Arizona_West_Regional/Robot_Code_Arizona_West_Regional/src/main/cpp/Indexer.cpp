#include "Indexer.h"

#pragma region Test Indexer functions
Indexer_Test::Indexer_Test() {}

void Indexer_Test::run_motor(double speed) {
  /*with toggle button you can change the indexer direction
    with R2 run spindexer motor*/
  static bool motorDirection = true;

  
  // if (joystick->GetRawButtonPressed(Indexer_Motor_Toggle_Joystick)) {
  //   motorDirection = !motorDirection;
  // }
  if (joystick->GetRawButtonReleased(Indexer_Motor_Toggle_Joystick)){
    if (motorDirection == true){
      motorDirection = false;
    }
    else if (motorDirection == false){
      motorDirection = true;
    }
  }

  if (motorDirection == true) {
    motor.SetSpeed(speed * joystick->GetRawAxis(Indexer_Motor_Joystick_Axis));
  } else if (motorDirection == false) {
    motor.SetSpeed(-speed * joystick->GetRawAxis(Indexer_Motor_Joystick_Axis));
  }
}

void Indexer_Test::init() {}

void Indexer_Test::run()  //(int networkTableColorValue)
{
  run_motor(Spindexer_Motor_Max_Speed);
}
#pragma endregion

#pragma region Indexer functions
Indexer::Indexer() : Indexer_Test() {}
#pragma endregion
