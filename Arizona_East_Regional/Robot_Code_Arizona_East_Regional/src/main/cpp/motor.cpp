#include "motor.h"

//Motor function talon and Sparkmax
Motor::Motor(int id, MotorType type, double max_speed, double acceleration, double deceleration, bool inverted)
    : type_(type)
{
    id_ = id;
    max_speed_ = max_speed;
    acceleration_ = acceleration;
    deceleration_ = deceleration;
    inverted_ = inverted;

    if (type_ == kTalonFX)
    {
        talon_ = new TalonFX(id_);
    }
    else if (type_ == kSparkMax)
    {
        spark_ = new rev::CANSparkMax(id_, rev::CANSparkMax::MotorType::kBrushless);
    }
}

//Setspeed function
void Motor::SetSpeed(double speed)
{
    if (speed > max_speed_)
    {
        speed = max_speed_;
    }
    if (speed < -max_speed_)
    {
        speed = -max_speed_;
    }
    double current_speed = GetSpeed();
    if (speed > current_speed)
    {
        current_speed += acceleration_;
        if (current_speed > speed)
        {
            current_speed = speed;
        }
    }
    else if (speed < current_speed)
    {
        current_speed -= deceleration_;
        if (current_speed < speed)
        {
            current_speed = speed;
        }
    }
    if (inverted_)
    {
        current_speed *= -1;
    }
    if (type_ == kTalonFX)
    {
        talon_->Set(ControlMode::PercentOutput, current_speed);
    }
    else if (type_ == kSparkMax)
    {
        spark_->Set(current_speed);
    }
    speed_ = current_speed;
}

//Get Speed
double Motor::GetSpeed()
{
    return speed_;
}

//Get Talon
TalonFX &Motor::GetTalon()
{
    return *talon_;
}

//Get Sparkmax
rev::CANSparkMax &Motor::GetSpark()
{
    return *spark_;
}
