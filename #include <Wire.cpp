#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create the PCA9685 object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

#define SERVO_CHANNEL_0 0
#define SERVO_CHANNEL_1 1
#define SERVO_CHANNEL_2 2

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.println("Ready for commands...");
}

void setServoAngle(uint8_t channel, float angle) {
  uint16_t pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command.length() > 0) {
      int commaIndex = command.indexOf(',');
      if (commaIndex > 0) {
        int servo = command.substring(0, commaIndex).toInt();
        float angle = command.substring(commaIndex + 1).toFloat();
        if (servo >= 0 && servo <= 2) {
          setServoAngle(servo, angle);
          Serial.print("Servo ");
          Serial.print(servo);
          Serial.print(" set to ");
          Serial.println(angle);
        }
      }
    }
  }
}