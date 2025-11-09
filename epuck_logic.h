// epuck_logic.h

#ifndef EPUCK_LOGIC_H
#define EPUCK_LOGIC_H

// Importiert die Strukturen aus der Hardware-Schicht
#include "epuck_hardware.h"

/**
 * Verarbeitet Sensorwerte und berechnet die Motor-Geschwindigkeiten.
 * @param readings Die aktuellen Messwerte der Distanzsensoren.
 * @return Die berechneten Geschwindigkeiten.
 */
MotorSpeeds logic_avoid_collision(PsReadings readings);

#endif