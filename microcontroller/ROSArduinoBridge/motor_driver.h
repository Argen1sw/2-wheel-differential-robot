/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_FORWARD  6 // --> IN1
  #define RIGHT_MOTOR_BACKWARD 5 // --> IN2
  #define LEFT_MOTOR_BACKWARD  9 // --> IN4
  #define LEFT_MOTOR_FORWARD   10 // --> IN3
  #define RIGHT_MOTOR_ENABLE 12 
  #define LEFT_MOTOR_ENABLE 13 
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
