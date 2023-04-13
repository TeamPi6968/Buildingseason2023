#ifndef MOTOR_H
#define MOTOR_H
//  https://maven.ctr-electronics.com/release/com/ctre/phoenixpro/PhoenixProAnd5-frc2023-latest.json
#include <ctre/Phoenix.h>
// https://software-metadata.revrobotics.com/REVLib-2023.json
#include <rev/CANSparkMax.h>
//Include user defined table (udt)
#include "MotorUDT.h"

class Motor
{
public:
  //Make motor function with the variable canid, type, max_speed, acceleration, deceleration and inverted
  Motor(int CanId, MotorType type, double max_speed, double acceleration, double deceleration, bool inverted);
  //Set Speed
  void SetSpeed(double speed);
  //Get Speed
  double GetSpeed();
  //Get talon
  TalonFX &GetTalon();
  //Get sparkMax
  rev::CANSparkMax &GetSpark();

private:
  //define talon
  TalonFX *talon_;
  //define Sparkmax
  rev::CANSparkMax *spark_;
  
  //define variable (see motor function)
  int id_;
  double speed_;
  double max_speed_;
  double acceleration_;
  double deceleration_;
  bool inverted_;
  MotorType type_;
};

#endif