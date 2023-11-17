#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_VL53L0X.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

DFRobot_VL53L0X sensor;

int x;
int y;
int touch;
int flex;
int mic;
int joystick_x = 0;
int joystick_y = 1;
int touch_sensor = 2;
int flex_sensor = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(touch_sensor, INPUT);
  pinMode(flex_sensor, INPUT);
  Wire.begin();
  //Set I2C sub-device address
  sensor.begin(0x50);
  //Set to Back-to-back mode and high precision mode
  sensor.setMode(sensor.eContinuous,sensor.eHigh);
  //Laser rangefinder begins to work
  sensor.start();
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  

}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  x = analogRead(joystick_x);
  y = analogRead(joystick_y);
  touch = analogRead(touch_sensor);
  flex = analogRead(flex_sensor);
  Serial.print(x);
  Serial.print(" a ");
  Serial.print(y);
  Serial.print(" b ");
  Serial.print(touch);
  Serial.print(" c ");
  Serial.print(flex);
  Serial.print(" d ");
  Serial.print(sensor.getDistance());
  Serial.print(" e ");
  Serial.print(a.acceleration.x+10);
  Serial.print(" f ");
  Serial.print(a.acceleration.y+10);
  Serial.println(" g ");
  delay(10);
}
