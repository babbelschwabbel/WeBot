// epuck_logic.c

#include "epuck_logic.h"
#include "epuck_hardware.h" // Für Konstanten wie MAX_SPEED
#include <stdbool.h>

#define OBSTACLE_THRESHOLD 80.0 // Schwelle, ab der ein Hindernis erkannt wird

/**
 * Verarbeitet Sensorwerte und berechnet die Motor-Geschwindigkeiten.
 */
MotorSpeeds logic_avoid_collision(PsReadings readings) {
    MotorSpeeds speeds;
    
    // 1. Hindernisse erkennen
    bool right_obstacle =
        readings.values[0] > OBSTACLE_THRESHOLD ||
        readings.values[1] > OBSTACLE_THRESHOLD ||
        readings.values[2] > OBSTACLE_THRESHOLD;
        
    bool left_obstacle =
        readings.values[5] > OBSTACLE_THRESHOLD ||
        readings.values[6] > OBSTACLE_THRESHOLD ||
        readings.values[7] > OBSTACLE_THRESHOLD;
        
    // 2. Standardgeschwindigkeit (Geradeaus)
    speeds.left_speed = 0.5 * MAX_SPEED;
    speeds.right_speed = 0.5 * MAX_SPEED;
    
    // 3. Ausweichmanöver
    if (left_obstacle) {
        // Nach rechts drehen
        speeds.left_speed  = 0.5 * MAX_SPEED;
        speeds.right_speed = -0.5 * MAX_SPEED;
    }
    else if (right_obstacle) {
        // Nach links drehen
        speeds.left_speed  = -0.5 * MAX_SPEED;
        speeds.right_speed = 0.5 * MAX_SPEED;
    }
    
    return speeds;
}