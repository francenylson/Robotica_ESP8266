#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SERVOMIN  0 // 150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  255 // this is the 'maximum' pulse length count (out of 4096)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
void setup()
{
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop()
{
 Serial.println("Red");
 pwm.reset();
 pwm.setPWM(0, 255,0);
 delay(2000);    

 Serial.println("Green");
 pwm.reset();
 pwm.setPWM(1, 255,0);
 delay(2000);    

 Serial.println("Blue");
 pwm.reset();
 pwm.setPWM(2, 255,0);
 delay(2000);    

}
