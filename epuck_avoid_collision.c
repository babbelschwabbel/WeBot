/*
 * File:          epuck_avoid_collision.c
 * Date:
 * Description:
 * Author: ich
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define MAX_SPEED 6.28

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {


  double obstacle_threshold = 80.0;
  /* necessary to initialize webots stuff */
  wb_robot_init();
  
  // initialize devices
  int i;
  WbDeviceTag ps[8];
  char ps_names[8][4] = {
    "ps0", "ps1", "ps2", "ps3",
    "ps4", "ps5", "ps6", "ps7"
  };
  
  for (i = 0; i < 8; i++) {
    ps[i] = wb_robot_get_device(ps_names[i]);
    wb_distance_sensor_enable(ps[i], TIME_STEP);
  }
  
  //initialize motors  
  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);


  while (wb_robot_step(TIME_STEP) != -1) {
    // read sensors outputs
    double ps_values[8];
    for (i = 0; i < 8; i++) {
      ps_values[i] = wb_distance_sensor_get_value(ps[i]);
    }
    
    // process behavior
    // detect obstacles
    bool right_obstacle =
      ps_values[0] > obstacle_threshold ||
      ps_values[1] > obstacle_threshold ||
      ps_values[2] > obstacle_threshold;
    bool left_obstacle =
      ps_values[5] > obstacle_threshold ||
      ps_values[6] > obstacle_threshold ||
      ps_values[7] > obstacle_threshold;
      
    // initialize motor speeds at 50% of MAX_SPEED.
    double left_speed  = 0.5 * MAX_SPEED;
    double right_speed = 0.5 * MAX_SPEED;
    
    // modify speeds according to obstacles
    if (left_obstacle) {
      // turn right
      left_speed  = 0.5 * MAX_SPEED;
      right_speed = -0.5 * MAX_SPEED;
    }
    else if (right_obstacle) {
      // turn left
      left_speed  = -0.5 * MAX_SPEED;
      right_speed = 0.5 * MAX_SPEED;
    }
    // write actuators inputs
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
    
  };

  /* Enter your cleanup code here */
  

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
