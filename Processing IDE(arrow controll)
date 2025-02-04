import processing.serial.*; // Import Serial library

Serial myPort; // Serial communication object
float servo0Angle = 90; // Initial angle for Servo 0 (gripper)
float servo1Angle = 90; // Initial angle for Servo 1 (arm up/down)
float servo2Angle = 90; // Initial angle for Servo 2 (rotation in Z axis)

void setup() {
  size(400, 400); // Set the window size
  myPort = new Serial(this, Serial.list()[0], 9600); // Open the first available serial port
  println("Use arrow keys or mouse to control the robotic arm.");
}

void draw() {
  background(200);

  // Display servo angles
  fill(0);
  textSize(16);
  text("Servo 0 (Gripper): " + servo0Angle, 20, 30);
  text("Servo 1 (Up/Down): " + servo1Angle, 20, 60);
  text("Servo 2 (Rotation): " + servo2Angle, 20, 90);

  // Simple UI for control instructions
  text("Controls:", 20, 150);
  text("Arrow Keys: Move Up/Down/Rotate", 20, 180);
  text("Trackpad: Adjust angles smoothly", 20, 210);
}

void keyPressed() {
  switch (keyCode) {
    case UP: // Increase Servo 1 (Up/Down)
      servo1Angle = constrain(servo1Angle + 5, 0, 180);
      sendServoCommand(1, servo1Angle);
      break;
    case DOWN: // Decrease Servo 1 (Up/Down)
      servo1Angle = constrain(servo1Angle - 5, 0, 180);
      sendServoCommand(1, servo1Angle);
      break;
    case LEFT: // Decrease Servo 2 (Rotation)
      servo2Angle = constrain(servo2Angle - 5, 0, 180);
      sendServoCommand(2, servo2Angle);
      break;
    case RIGHT: // Increase Servo 2 (Rotation)
      servo2Angle = constrain(servo2Angle + 5, 0, 180);
      sendServoCommand(2, servo2Angle);
      break;
    case 'o': // Open gripper (Servo 0)
      servo0Angle = constrain(servo0Angle + 5, 0, 180);
      sendServoCommand(0, servo0Angle);
      break;
    case 'c': // Close gripper (Servo 0)
      servo0Angle = constrain(servo0Angle - 5, 0, 180);
      sendServoCommand(0, servo0Angle);
      break;
  }
}

void mouseDragged() {
  // Map mouse X and Y positions to servo angles
  servo1Angle = map(mouseY, 0, height, 0, 180);
  servo2Angle = map(mouseX, 0, width, 0, 180);
  
  servo1Angle = constrain(servo1Angle, 0, 180);
  servo2Angle = constrain(servo2Angle, 0, 180);

  sendServoCommand(1, servo1Angle);
  sendServoCommand(2, servo2Angle);
}

void sendServoCommand(int servo, float angle) {
  if (myPort != null) {
    // Send servo ID and angle as a formatted string
    myPort.write(servo + "," + (int)angle + "\n");
  }
}