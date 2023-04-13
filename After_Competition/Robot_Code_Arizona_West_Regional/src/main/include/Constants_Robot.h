#ifndef CONSTANTS_ROBOT_H
#define CONSTANTS_ROBOT_H
#include "MotorUDT.h"
#include <frc/smartdashboard/SmartDashboard.h>

/*----------Joystick explenation----------
In competition there are two joysticks, one for operator and one for the drive*/

/*----------Motor parameter explenation, this is for all the motor variables
that the user can select----------
- Select MotorType: SparkMax or talon [check which motorcontroller you have]
- Select Can Id of the motor, each motor should have there unique id. You can
determine can ID with phoenix tuner or Rev hardware client, depending on which
motorcontroller you have
- Select if the motor is inverted or not [in which direction the motor rotates,
clock wise of counter clock wise]
- Select max speed or the motor, when the motor is not inverted then the speed
varies from [0 to 1] else if the motor is inverted then the speed varies between
[0 to -1]
- Select acceleration value of the motor
- Select deceleration value of the motor*/

/*choose here the port of the Joysticks*/
constexpr unsigned char kOperatorJoystickPort = 1; 
constexpr unsigned char kDriversJoystickPort = 0;

/*---------------------------Intake joystick control-------------------------------*/
constexpr unsigned char Intake_Pneumatic_Toggle_Joystick = 8; /*square stick press*/
constexpr unsigned char Intake_Motor_Axis_Joystick = 2; /*L2 trigger to change the speed of the motors*/

constexpr unsigned char Intake_Motor_Axis_Reverse_Joystick = 3;

constexpr unsigned char Indexer_Motor_Toggle_Joystick = 6;      //R1
constexpr unsigned char Indexer_Motor_Joystick_Axis = 3;        //L3


/*--------------------------Outtake joystick control--------------------------------*/
constexpr unsigned char Gripper_Pneumatic_Open_Joystick = 5;  //L2
constexpr unsigned char Active_Gripper_Motor_Button = 6; // R1
//constexpr unsigned char Gripper_Pneumatic_Close_Joystick = 10; //Right stick press 

/*----------Lift Positions Buttons---------------------------*/
constexpr unsigned char Indexer_Position_Button = 1;
constexpr unsigned char Home_Position_Button = 2;
constexpr unsigned char Ground_Position_Button = 3;
constexpr unsigned char Mid_Position_Button = 4;
constexpr unsigned char High_Position_Button = 5;
constexpr unsigned char Loading_Position_Button = 7;//7; //Dit overbruggen en button aan toevoegen


/*----------Top Intake motor with talon----------*/
/*define motorcontroller type kSparkMax or TalonFx, can ID, Max-speed,
 * acceleration, deceleration, inverted, Joystick button*/
constexpr MotorType Top_Intake_Motor_Type = kTalonFX;
constexpr unsigned char Top_Intake_Motor_Can_Id = 9; 
constexpr double Top_Intake_Motor_Max_Speed = 0.4; 
constexpr double Top_Intake_Motor_Acceleration = 1;
constexpr double Top_Intake_Motor_Deceleration = 1;
constexpr bool Top_Intake_Motor_Inverted = true;

/*-------------------Bottom Intake motor with sparkmax-----------*/
/*define motorcontroller type kSparkMax or TalonFx, can ID, Max-speed,
 * acceleration, deceleration, inverted, Joystick button*/
constexpr MotorType Bottom_Intake_Motor_Type = kSparkMax;
constexpr unsigned char Bottom_Intake_Motor_Can_Id = 21;
constexpr double Bottom_Intake_Motor_Max_Speed = 0.5;
constexpr double Bottom_Intake_Motor_Acceleration = 1;
constexpr double Bottom_Intake_Motor_Deceleration = 1;
constexpr bool Bottom_Intake_Motor_Inverted = true;

/*----------Spindexer Motor----------*/
constexpr MotorType Spindexer_Motor_Type = kSparkMax;
constexpr unsigned char Spindexer_Motor_Can_Id = 22;
constexpr double Spindexer_Motor_Max_Speed = 0.2;
constexpr double Spindexer_Motor_Acceleration = 1;
constexpr double Spindexer_Motor_Deceleration = 1;
constexpr bool Spindexer_Motor_Inverted = false;

/*----------Pneumatics intake----------*/
/*define can ID and the channel 1 and 2 (channel 1 for forward and channel 2 for
 * backwards)*/
constexpr unsigned char Pneumatic_Can_Id = 5;
constexpr unsigned char Intake_Pneumatic_Channel_1 = 0;
constexpr unsigned char Intake_Pneumatic_Channel_2 = 1;

/*----------Pneumatics gripper----------*/
constexpr unsigned char Gripper_Pneumatic_Channel_1 = 2;
constexpr unsigned char Gripper_Pneumatic_Channel_2 = 3;

/*----------Lift Encoder----------*/
/*values for normalisation
-> min value is min real value of encoder
-> max value is max real value of encoder
-> min position and max position transforms 
   encoder values to angels 0 to 360*/
constexpr double Lift_Encoder_Min_Value = 0;
constexpr double Lift_Encoder_Max_Value = 1;
constexpr double Lift_Min_Position = 0;
constexpr double Lift_Max_Position = 360;

/*----------Lift PID Constants----------*/
constexpr double kP_Lift = 0.01;//0.01;//0.0125; //0.008 is niet goed
constexpr double kI_Lift = 0;
constexpr double kD_Lift = 0;

/*----------Lift PID Constants in auto----------*/
constexpr double kP_Lift_Auto = 0.002;
constexpr double kI_Lift_Auto = 0;
constexpr double kD_Lift_Auto = 0;

/*----------Gripper motor----------*/
constexpr MotorType Gripper_Motor_Type = kSparkMax;
constexpr unsigned char Gripper_Motor_Can_Id = 50;//can id testen en 
//double Gripper_Motor_Speed_Max_Out;
constexpr double Gripper_Motor_Speed_Zero = 0;
constexpr double Gripper_Motor_Speed_In = 0.7;
constexpr double Gripper_Motor_Speed_Out_ground = 0.7;
constexpr double Gripper_Motor_Speed_Out_mid = 0.7;
constexpr double Gripper_Motor_Speed_Out_High = 0.7;
constexpr double Gripper_Motor_Speed_Out_Loading = 0.7;
constexpr double Gripper_Motor_Speed_Out_ChargeStation_DreamJoep = 0.7;
constexpr double Gripper_Motor_Acceleration = 1;
constexpr double Gripper_Motor_Deceleration = 1;
constexpr bool Gripper_Motor_Inverted = false;
constexpr double Gripper_Motor_Speed_Max = 0.5;

/*----------Lift Left Motor----------*/
constexpr MotorType Lift_Left_Motor_Type = kSparkMax;
constexpr unsigned char Lift_Left_Motor_Can_Id = 23;
constexpr double Lift_Left_Motor_Max_Speed =0.25; //0.15;
constexpr double Lift_Left_Motor_Acceleration = 1;
constexpr double Lift_Left_Motor_Deceleration = 1;
constexpr bool Lift_Left_Motor_Inverted = false;

/*----------Lift Right Motor----------*/
constexpr MotorType Lift_Right_Motor_Type = kSparkMax;
constexpr unsigned char Lift_Right_Motor_Can_Id = 20;
constexpr double Lift_Right_Motor_Max_Speed = 0.25;//0.15;
constexpr double Lift_Right_Motor_Acceleration = 1;
constexpr double Lift_Right_Motor_Deceleration = 1;
constexpr bool Lift_Right_Motor_Inverted = true;

/*----------Arm Encoder----------*/
/* see explenation lift encoder 
   (length instead of angles)*/
constexpr double Arm_Encoder_Min_Value = 0;
constexpr double Arm_Encoder_Max_Value = 3;//3.36;
constexpr double Arm_Min_Position = 0;
constexpr double Arm_Max_Position = 36;

/*----------Arm Positions----------*/
/*[needs to be define and test]*/
constexpr double Indexer_Length = 1;//14;
constexpr double Home_Length = 1;//0;
constexpr double Ground_Length = 1;//35;//36;
constexpr double Mid_Length = 1;//21;//21;
constexpr double High_Length = 1;//35;//36;
//constexpr double Loader_Length = 35; //Dit overbruggen voor testen

/*----------Arm PID Constants----------*/
constexpr double kP_Arm = 0.025;
constexpr double kI_Arm = 0;
constexpr double kD_Arm = 0;

/*----------Arm Motor----------*/
constexpr MotorType Arm_Motor_Type = kSparkMax;
constexpr unsigned char Arm_Motor_Can_Id = 24;
constexpr double Arm_Motor_Max_Speed = 0.10;
constexpr double Arm_Motor_Acceleration = 1;
constexpr double Arm_Motor_Deceleration = 1;
constexpr bool Arm_Motor_Inverted = false;

/*----------Lift Positions----------*/
/*[Needs to be tested]*/
constexpr double Indexer_Angle = 5;//10;
constexpr double Home_Angle = 40;//33;//28;
constexpr double Ground_Angle = 60;//55;
constexpr double Mid_Angle = 125;
constexpr double High_Angle = 140;
constexpr double Loading_Angle = 128; // Dit overbruggen tijdens test



//Intake auto
//constexpr MotorType Test_Intake_Motor_Type = kSparkMax;
//constexpr unsigned char Test_Intake_Motor_Can_Id = 40; 
//constexpr double Test_Intake_Motor_Max_Speed = 0.3; 
//constexpr double Test_Intake_Motor_Acceleration = 1;
//constexpr double Test_Intake_Motor_Deceleration = 1;
//constexpr bool Test_Intake_Motor_Inverted = false;


//Auto Snelheden
constexpr double Speed_Arm_Retraction = -0.1;
constexpr double Speed_Arm_Extention = 0.1;




#endif