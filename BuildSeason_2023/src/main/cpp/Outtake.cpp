#pragma once
#include "Outtake.h"

Outtake::Outtake(frc::PS4Controller *controller){
  Outtake_controller = controller; 
}

void Outtake::init(){
  // enable compressor (digital and analog added for now)
  compressor.EnableAnalog(100_psi, 120_psi); // Can't be higher then 120 psi
  //compressor.EnableDigital();

  // Read start value encoder
  current_angle = Encoder_Motor_1.GetPosition(); // value between 0 and 1

  // Follow function Motor 2 and set it inverted
  bool inverted = true;
  Motor_2.Follow(Motor_1, inverted);

  // Set PID
  pid_1.SetPID(kP_1, kI_1, kD_1);
}

void Outtake::mainloop(){
  // Read current encoder value
  current_angle = Encoder_Motor_1.GetPosition(); // value between 0 and 1
  switch (State_Outtake)
  {
    case 0:
      // Read button controller
      Button_outtake = Outtake_controller->GetSquareButton(); 
      if(Button_outtake == true){
        // activate cylinder for gripper
        Solenoid.Set(frc::DoubleSolenoid::Value::kForward);
        State_Outtake = 1;
      }
      break;

    case 1:
      // move to desired position motor
      Motor_1.Set(speedLimiter_rotations * pid_1.Calculate(current_angle, target_angle));
      if(current_angle == target_angle){
        // Read current time
        time.Reset();
        time.Start();
        State_Outtake = 2;
      }
      break;

    case 2:
      // Read time
      Time = time.Get();
      // Set extention
      Motor_Extension.Set(percent_speed);
      if(Time > Delay){
        // Deactivate cylinder for gripper
        Solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
        State_Outtake = 3;
      }
      break;

      case 3:
      // Move to start position
      Motor_1.Set(speedLimiter_rotations * pid_1.Calculate(current_angle, start_angle));
      if(current_angle == start_angle){
        State_Outtake = 0;
      }
      break;
  
    default:
      break;
  }
}

