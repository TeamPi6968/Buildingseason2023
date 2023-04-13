#include "Outtake.h"

#pragma region Test Outtake functions

/*---------intitialize begin positions and PID values --------------*/
/*can be change to initialise*/
void Outtake_Test::init() {
  encoder_arm.SetPosition(0);
  double liftPID[3] = {kP_Lift, kI_Lift, kD_Lift};
  //double liftPIDAuto[3] = {kP_Lift_Auto, kI_Lift_Auto, kD_Lift_Auto};
  double armPID[3] = {kP_Arm, kI_Arm, kD_Arm};
 // tunePID(liftPID, armPID, liftPIDAuto);
}

/*---------Normalisation of the sensors (this function works for both
 * encoders)-------------------*/
Outtake_Test::Outtake_Test() {}
double Outtake_Test::normalization(double value, double min_value,
                                   double max_value, double min_range,
                                   double max_range) {
  return (value - min_value) * (max_range - min_range) /
         (max_value - min_value);
}

/*----------Get the position of the lift----------*/
double Outtake_Test::getLiftPosition() {
  return abs(encoder_lift.GetPosition());
}

/*----------Get the position of the arm ----------*/
double Outtake_Test::getArmPosition() {
  return normalization(abs(encoder_arm.GetPosition()), Arm_Encoder_Min_Value,
                       Arm_Encoder_Max_Value, Arm_Min_Position,
                       Arm_Max_Position);
}

/*----------Zero position for incremental encoder----------*/
/*----------Absolute encoder does not need zero position----------*/
/*(DO NOT CHANGE ANYTHING)*/
void Outtake_Test::setZeroPosition() { encoder_arm.SetPosition(0); }

/*---------Tuning the PID values ---------*/
/*----------Changes only in the constants----------*/
/*(DO NOT CHANGE)*/
void Outtake_Test::tunePID(double lift_constants[], double arm_constants[]) {
  liftPID->SetPID(lift_constants[0], lift_constants[1], lift_constants[2]);
  armPID->SetPID(arm_constants[0], arm_constants[1], arm_constants[2]);
  //liftPIDAuto->SetPID(lift_constants_Auto[0], lift_constants_Auto[1], lift_constants_Auto[2]);
}

/*Lift to the position*/
/*Do not change*/
void Outtake_Test::liftToPosition(double &current_angle, double target_angle,
                                  bool follow_motor_inverted) {
  frc::SmartDashboard::PutNumber(
      "speed", liftPID->Calculate(current_angle, target_angle));
  current_angle = getLiftPosition();
  liftLeftMotor.SetSpeed(-liftPID->Calculate(current_angle, target_angle));
  liftRightMotor.GetSpark().Follow(liftLeftMotor.GetSpark(),
                                   follow_motor_inverted);
}

/*------------------------Auto
 * extend------------------------------------------*/
/*dit stukje was overbrugt*/
 /*void Outtake_Test::armToPosition(double &current_position,
                                  double target_position) {
   current_position = getArmPosition();
   armMotor.SetSpeed(armPID->Calculate(current_position, target_position));
 }*/
/*------------------------------------------------------------------------------*/

unsigned char Outtake_Test::getPositionButton() {


  if (joystick->GetRawButton(2)) {
    return iterators::Mid_Position;
  } else if (joystick->GetRawButton(8)) {
    return iterators::Indexer_Position;
  } else if (joystick->GetRawButton(4)) {
    // return iterators::High_Position;
    return iterators::Loading_Position;
  } else if (joystick->GetRawButton(1)) {
    return iterators::Ground_Position;
  } else if (joystick->GetRawButton(3)) {
    return iterators::Home_Position;
   } 
  // else if (joystick ->GetRawButton(7)){//7)){ //Dit overbruggen tijdens testen
  //   return iterators::Loading_Position;
  // }
  else {
    return Idle;
  }
}

void Outtake_Test::togglePositions(bool toggle_positions[]) {
  for (int i = 0; i < 5; i++) {
    if (i == getPositionButton()) {
      toggle_positions[i] = true;
    } else if (getPositionButton() != Idle) {
      toggle_positions[i] = false;
    }
  }
  frc::SmartDashboard::PutNumber("return", getPositionButton());
  frc::SmartDashboard::PutNumber("Indexer_Position",
                                 toggle_positions[Indexer_Position]);
  frc::SmartDashboard::PutNumber("Home_Position",
                                 toggle_positions[Home_Position]);
  frc::SmartDashboard::PutNumber("Ground_Position",
                                 toggle_positions[Ground_Position]);
  frc::SmartDashboard::PutNumber("Mid_Position",
                                 toggle_positions[Mid_Position]);
   frc::SmartDashboard::PutNumber("Loading_Position",
                                  toggle_positions[Loading_Position]);
 frc::SmartDashboard::PutNumber("High_Position",
                                 toggle_positions[High_Position]);
}

std::pair<double, double> Outtake_Test::positionSelection(
    bool toggle_positions[], bool &start_moving) {
  static double target_angle = 0;
  static double target_length = 0;

  if (toggle_positions[Indexer_Position]) {
    target_angle = Indexer_Angle;
    target_length = Indexer_Length;
    start_moving = true;
  } else if (toggle_positions[Home_Position]) {
    target_angle = Home_Angle;
    target_length = Home_Length;
    start_moving = true;
  } else if (toggle_positions[Ground_Position]) {
    target_angle = Ground_Angle;
    target_length = Ground_Length;
    start_moving = true;
  } else if (toggle_positions[Mid_Position]) {
    target_angle = Mid_Angle;
    target_length = Mid_Length;
    start_moving = true;
  } else if (toggle_positions[Loading_Position]) {
    target_angle = Loading_Angle;
    //target_length = Loader_Length;
    start_moving = true;
  }
   else if (toggle_positions[High_Position]) {
    target_angle = High_Angle;
    target_length = High_Length;
    start_moving = true;
  } else {
    target_angle = Home_Angle;
    target_length = Home_Length;
  }

  return {target_angle, target_length};
}
/*not used*/
void Outtake_Test::counterPositions(unsigned char &counter,
                                    bool forward_position_button,
                                    bool backward_position_button,
                                    bool home_position_button) {
  if (counter < 4 && forward_position_button) {
    counter++;
  } else if (counter > 0 && backward_position_button) {
    counter--;
  } else if (home_position_button) {
    counter = 1;
  }
} /*not used*/

/*not used*/
std::pair<double, double> Outtake_Test::positionSelection(int counter,
                                                          bool &start_moving) {
  static double target_angle = 0;
  static double target_length = 0;

  switch (counter) {
    case Indexer_Position: {
      target_angle = Indexer_Angle;
      target_length = Indexer_Length;
      start_moving = true;
      break;
    }

    case Home_Position: {
      target_angle = Home_Angle;
      target_length = Home_Length;
      start_moving = true;
      break;
    }

    case Ground_Position: {
      target_angle = Ground_Angle;
      target_length = Ground_Length;
      start_moving = true;
      break;
    }
    case Mid_Position: {
      target_angle = Mid_Angle;
      target_length = Mid_Length;
      start_moving = true;
      break;
    }
    case High_Position: {
      target_angle = High_Angle;
      target_length = High_Length;
      start_moving = true;
      break;
    }
  }

  return {target_angle, target_length};
} /*not used*/

void Outtake_Test::runToPosition() {
  static std::pair<double, double> target_positions{Home_Angle, Home_Length};
  static double current_angle = Home_Angle;
  static double current_position = Home_Length;
  static bool position_state[6] = {false};
  static bool start_moving = false;
  current_angle = getLiftPosition();

  frc::SmartDashboard::PutNumber("current angle", current_angle);
  togglePositions(position_state);  // mandatory

  target_positions =
      positionSelection(position_state, start_moving);  // mandatory

  liftLeftMotor.SetSpeed(
      liftPID->Calculate(current_angle, target_positions.first));

  liftRightMotor.GetSpark().Follow(liftLeftMotor.GetSpark(), true);

  /*manual arm*/
  if (joystick->GetRawAxis(4)) {
    current_position = getArmPosition();
    armMotor.SetSpeed(joystick->GetRawAxis(4));
  } else {
    armMotor.SetSpeed(armPID->Calculate(getArmPosition(), current_position));
  } /*manual arm*/

  /*Gripper safety condition, the max limit can be changed if needed*/
  if (current_angle > 30 && current_angle < 45) {
    gripperSolenoid.Set(frc::DoubleSolenoid::kReverse);
  }

  /*-- -- -- -- -- -- --auto code
                         arm-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
                         
  if( (target_positions.first != Indexer_Angle && target_positions.first !=
   Home_Angle)) { armMotor.SetSpeed( armPID->Calculate(current_position,
   target_positions.second));
   }*/
  //--------------auto code arm---------------------------------

  if (current_angle > target_positions.first - 5 &&
      current_angle < target_positions.first + 5 &&
      (target_positions.first != Indexer_Angle &&
       target_positions.first != Home_Angle)) {
    /*armMotor.SetSpeed(
        armPID->Calculate(current_position, target_positions.second));
  */}
    frc::SmartDashboard::PutNumber("current_arm", current_position);
    frc::SmartDashboard::PutNumber("current_arm_real",
                                   encoder_arm.GetPosition());
}

void Outtake_Test::gripperAcutation() {
     /*Variable*/
  static bool Gripper_Open_Position;

  /*toggle*/
  if (joystick->GetRawButtonPressed(Gripper_Pneumatic_Open_Joystick)) {
    Gripper_Open_Position = !Gripper_Open_Position;
  }
  frc::SmartDashboard::PutBoolean(
      " gripper_Toggle", Gripper_Open_Position); /*print to check if toggle works*/

  /*move gripper to forward direction*/
  if (Gripper_Open_Position == true) {
    gripperSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
    frc::SmartDashboard::PutBoolean(
        "gripper_open", true); /*print to see the forward direction*/
    frc::SmartDashboard::PutBoolean(
        "gripper_dicht",
        false); /*print to see the reverse direction */
  }

  /*move intake to reverse direction*/
  else if (Gripper_Open_Position == false) {
    gripperSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    frc::SmartDashboard::PutBoolean(
        "gripper_open",
        false); /*print to see the forward direction*/
    frc::SmartDashboard::PutBoolean(
        "gripper_dicht", true); /*print to see the reverse direction*/
  }
}

void Outtake_Test::run() {
    runToPosition();
    frc::SmartDashboard::PutNumber("encoder_pos",
                                   abs(encoder_arm.GetPosition()));
    frc::SmartDashboard::PutNumber("current_arm_real",
                                   encoder_arm.GetPosition());
    frc::SmartDashboard::PutNumber("current_arm_real", getArmPosition());
    
    gripperAcutation();
    runActiveGripper();
}

void Outtake_Test::runActiveGripper() {
  if (joystick->GetRawButton(Active_Gripper_Motor_Button)) {
    gripperMotor.SetSpeed(Gripper_Motor_Max_Speed);
  }
}
//void Outtake_Test::runToPositionAuto(){
  //static double current_angle_auto = getLiftPosition();
  //static double target_positions_auto = Ground_Angle;
  //liftLeftMotor.SetSpeed(liftPIDAuto->Calculate(current_angle_auto, target_positions_auto));
  //liftRightMotor.GetSpark().Follow(liftLeftMotor.GetSpark(),true);
  //if (getLiftPosition() >= (Ground_Angle-1)){
  //  liftLeftMotor.SetSpeed(0.01);
  //  liftRightMotor.GetSpark().Follow(liftLeftMotor.GetSpark(),true);
 // }
//}

//void Outtake_Test::gripperActuationAuto(){
  //if (getLiftPosition() >= (Ground_Angle - 1)){ //&& getLiftPosition() <= (Ground_Angle +1)){
   // gripperSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
 // }
//}

//void Outtake_Test::autonomous(){
// runToPositionAuto();
 //gripperActuationAuto();
//}



#pragma endregion

#pragma region Outtake functions

Outtake::Outtake() : Outtake_Test() {}

#pragma endregion
