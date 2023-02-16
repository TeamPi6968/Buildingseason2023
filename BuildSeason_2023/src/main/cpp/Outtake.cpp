#include "Outtake.h"

#pragma region Test Outtake functions

Outtake_Test::Outtake_Test()
{

}

void Outtake_Test::init(){
    follow_lift_motor.Follow(main_lift_motor, true);
}

void Outtake_Test::periodic(bool button_L, bool button_R){
      if (button_L == true)
  {
    main_lift_motor.Set(0.1);
  }
  else if(button_R = true){
    main_lift_motor.Set(-0.1);
  }
  else
  {
    main_lift_motor.Set(0);
  }
}

#pragma endregion

#pragma region Outtake functions

Outtake::Outtake() : Outtake_Test()
{
}

#pragma endregion


