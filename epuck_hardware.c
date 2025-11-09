// epuck_hardware.c

#include "epuck_hardware.h"
#include <webots/robot.h>
#include <stdbool.h>

// Globale Variablen (privat zu diesem Modul) für die Gerätekennungen
static WbDeviceTag ps[PS_COUNT];
static WbDeviceTag left_motor;
static WbDeviceTag right_motor;

/**
 * Initialisiert alle Webots Geräte
 */
void hardware_init(int timestep) {
    wb_robot_init();

    // Distanzsensoren initialisieren
    char ps_names[PS_COUNT][4] = {
        "ps0", "ps1", "ps2", "ps3",
        "ps4", "ps5", "ps6", "ps7"
    };
    
    for (int i = 0; i < PS_COUNT; i++) {
        ps[i] = wb_robot_get_device(ps_names[i]);
        wb_distance_sensor_enable(ps[i], timestep);
    }

    // Motoren initialisieren
    left_motor = wb_robot_get_device("left wheel motor");
    right_motor = wb_robot_get_device("right wheel motor");

    // Motoren auf Geschwindigkeitssteuerung einstellen
    wb_motor_set_position(left_motor, INFINITY);
    wb_motor_set_position(right_motor, INFINITY);
    wb_motor_set_velocity(left_motor, 0.0);
    wb_motor_set_velocity(right_motor, 0.0);
}

/**
 * Liest alle Distanzsensoren aus.
 */
PsReadings hardware_get_ps_readings() {
    PsReadings readings;
    for (int i = 0; i < PS_COUNT; i++) {
        readings.values[i] = wb_distance_sensor_get_value(ps[i]);
    }
    return readings;
}

/**
 * Setzt die Geschwindigkeiten der Motoren.
 */
void hardware_set_speed(double left_speed, double right_speed) {
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
}