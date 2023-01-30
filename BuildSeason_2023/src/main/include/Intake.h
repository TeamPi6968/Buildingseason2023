#include <frc/PS4Controller.h>
#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>

class Intake{
    private:
    frc::PS4Controller *intakecontroller;
    int Can_id_compressor;
    frc::Compressor compressor{Can_id_compressor, frc::PneumaticsModuleType::REVPH};
    int connection_1;
    int connection_2;
    frc::DoubleSolenoid solenoid{Can_id_compressor, frc::PneumaticsModuleType::REVPH, connection_1, connection_2};
    // Which motors? and how many?

    public:
    Intake(frc::PS4Controller *controller);
    void init();
    void mainloop();
};