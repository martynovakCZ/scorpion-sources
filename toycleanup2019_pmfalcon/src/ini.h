#include <atomic>

using rb::LED_GREEN;

#define RIGHT_MOTOR  rb::MotorId::M8
#define LEFT_MOTOR  rb::MotorId::M1


byte qrd[12];  // pole, do ktereho se nacitaji okamzite hodnoty QRD senzoru 
byte qrd_prumer[12];
std::atomic_bool end_L;
std::atomic_bool end_R;

Servo servo; 

int servo_open = 100;
int servo_close = 180;
int position_servo = 100; // pro postupne krokovani serva pro kalibraci 
int power_motor = 80;
int otacka = 235; // pocet tiku na otacku 
int ctverec = 250; // pocet tiku na ctverec - Praha
int zatoc = 280;  // pocet tiku na zatoceni o 90 stupnu
static const uint32_t i2c_freq = 400000;
bool L_G_light = false; // pro blikani zelene LED - indikuje, ze deska funguje 

rb::Manager& rbc() 
{
    static rb::Manager m(false);  // ve výchozím stavu se motory po puštění tlačítka vypínají, false zařídí, že pojedou, dokud nedostanou další pokyn 
    return m;
}