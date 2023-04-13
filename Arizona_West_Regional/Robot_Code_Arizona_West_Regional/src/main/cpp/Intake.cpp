#include "Intake.h"

#pragma region Test Intake functions

Intake_Test::Intake_Test() {}

/*-------------------Pneumatics---------------------------------------------*/
void Intake_Test::actuate_pneumatics() {
  /*Variable*/
  static bool intake_Forward_Position;

  /*toggle*/
  if (joystick->GetRawButtonPressed(Intake_Pneumatic_Toggle_Joystick)) {
    intake_Forward_Position = !intake_Forward_Position;
  }
  frc::SmartDashboard::PutBoolean(
      " intake_Toggle", intake_Forward_Position); /*print to check if toggle works*/

  /*move intake to forward direction*/
  if (intake_Forward_Position == true) {
    doubleSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
    frc::SmartDashboard::PutBoolean(
        "intake_Forward_Position", true); /*print to see the forward direction*/
    frc::SmartDashboard::PutBoolean(
        "intake_Reverse_Position",
        false); /*print to see the reverse direction */
  }

  /*move intake to reverse direction*/
  else if (intake_Forward_Position == false) {
    doubleSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    frc::SmartDashboard::PutBoolean(
        "intake_Forward_Position",
        false); /*print to see the forward direction*/
    frc::SmartDashboard::PutBoolean(
        "intake_Reverse_Position", true); /*print to see the reverse direction*/
  }
}


/*-------------------motors---------------------------------------------*/
void Intake_Test::run_motors(double topMotorSpeed, double bottomMotorSpeed) {

/*bottomMotor intake*/
  if (joystick->GetRawAxis(3)){
    bottomMotor.SetSpeed(-bottomMotorSpeed *
                       joystick->GetRawAxis(3));
     topMotor.SetSpeed(-topMotorSpeed *
                       joystick->GetRawAxis(3));
  }else{
  bottomMotor.SetSpeed(bottomMotorSpeed *
                       joystick->GetRawAxis(2));
  topMotor.SetSpeed(topMotorSpeed *
                    joystick->GetRawAxis(2));
   
  }
  frc::SmartDashboard::PutNumber("topMotor_Speed", topMotor.GetSpeed());
  frc::SmartDashboard::PutNumber("bottomMotor_Speed", bottomMotor.GetSpeed());
}

  void Intake_Test::run_motors_auto() {
    bottomMotor.SetSpeed(-0.2);
    topMotor.SetSpeed(-0.2);
  }
  void Intake_Test::stop_motors_auto() {
    bottomMotor.SetSpeed(0);
    topMotor.SetSpeed(0);
  }

 
 




//auto
 //void Intake_Test::run_motors_auto(double topMotorSpeedAuto, double bottomMotorSpeed){
  //bottomMotor.setSpeed
 //}

// void Intake_Test::run_motors_reverse(double topMotorSpeedreverse, double bottomMotorSpeedreverse){
//   /*bottomMotor intake*/
//  bottomMotor_Reverse.SetSpeed(-bottomMotorSpeedreverse *
//                        joystickdriver ->GetRawAxis(Intake_Motor_Axis_Reverse_Joystick));
//   frc::SmartDashboard::PutNumber("bottomMotorReverse_Speed", bottomMotor_Reverse.GetSpeed());
 

// /*topMotor intake*/
//   topMotor_Reverse.SetSpeed(-topMotorSpeedreverse *
//                     joystickdriver ->GetRawAxis(Intake_Motor_Axis_Reverse_Joystick));
//   frc::SmartDashboard::PutNumber("topMotorReverse_Speed", topMotor_Reverse.GetSpeed());
// }
/*-------------------intake init------------------------------------------*/
void Intake_Test::init() {}

/*-------------------run intake--------------------------------------------*/
void Intake_Test::run() {
  actuate_pneumatics();
  //frc::SmartDashboard::PutNumber("test", frc::SmartDashboard::GetNumber("test", Top_Intake_Motor_Max_Speed));
    //frc::SmartDashboard::GetNumber("test", Top_Intake_Motor_Max_Speed);
  run_motors(Top_Intake_Motor_Max_Speed, Bottom_Intake_Motor_Max_Speed);
  }

#pragma endregion

#pragma region Intake functions

Intake::Intake() : Intake_Test() {}

#pragma endregion
