/*
 * File: epuck_avoid_collision.c
 * FIX: Nutzt C-Includes, um die Implementierungsdateien direkt zu verarbeiten.
 */

#include "epuck_hardware.h" 
#include "epuck_logic.h"    

int main(int argc, char **argv) {
  hardware_init(TIME_STEP);
  
  while (wb_robot_step(TIME_STEP) != -1) {
    PsReadings readings = hardware_get_ps_readings();
    MotorSpeeds speeds = logic_avoid_collision(readings);
    hardware_set_speed(speeds.left_speed, speeds.right_speed);
  }
  
  wb_robot_cleanup();
  return 0;
}

// ------------------------------------------------------------------
// ** KOMPILIERUNGS-FIX: ALLE IMPLEMENTIERUNGEN HIER EINSCHLIESSEN **
// ------------------------------------------------------------------

#include "epuck_hardware.c" // <-- Fügt den Code hier ein
#include "epuck_logic.c"    // <-- Fügt den Code hier ein