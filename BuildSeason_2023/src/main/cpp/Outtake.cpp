#include "Outtake.h"

#pragma region Test Outtake functions

Outtake_Test::Outtake_Test()
{

}

void Outtake_Test::init(){
    follow_lift_motor.Follow(main_lift_motor, true);
}

void Outtake_Test::periodic(){
      if (controller.GetSquareButton() == true)
  {
    main_lift_motor.Set(0.1);
  }
  else if(controller.GetCircleButton()){
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


