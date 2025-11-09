// epuck_hardware.h

#ifndef EPUCK_HARDWARE_H
#define EPUCK_HARDWARE_H

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>

// --- KONSTANTEN ---
#define TIME_STEP 64      // Standard time step in ms
#define MAX_SPEED 6.28    // Maximum wheel speed of the e-puck
#define PS_COUNT 8        // Number of distance sensors

// --- DATENSTRUKTUREN ---

// Struktur zum Halten aller Distanzsensor-Messwerte
typedef struct {
    double values[PS_COUNT];
} PsReadings;

// Struktur zum Halten der Motor-Geschwindigkeiten
typedef struct {
    double left_speed;
    double right_speed;
} MotorSpeeds;

// --- FUNKTIONSPROTOTYPEN ---

/**
 * Initialisiert Webots, alle Sensoren (PS) und Motoren.
 * @param timestep Der Zeitschritt für die Sensoraktivierung.
 */
void hardware_init(int timestep);

/**
 * Liest alle Distanzsensoren aus.
 * @return Eine Struktur mit den aktuellen Sensorwerten.
 */
PsReadings hardware_get_ps_readings();

/**
 * Setzt die Geschwindigkeiten der linken und rechten Motoren.
 * @param left_speed Die Geschwindigkeit für den linken Motor.
 * @param right_speed Die Geschwindigkeit für den rechten Motor.
 */
void hardware_set_speed(double left_speed, double right_speed);

#endif