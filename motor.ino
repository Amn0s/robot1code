void motor() {
  // Calculate heading error
  float error = heading - targetHeading;

  // Normalize error to [-180, 180] range
  if (error > 180) error -= 360;
  if (error < -180) error += 360;

  // Use the magnitude of the error to scale correction
  float absError = abs(error);         // Get magnitude
  absError = min(absError, 90);        // Cap error to prevent overcorrection

  int maxCorrection = 70;              // Max adjustment to apply
  float multiplier = absError / 90;  // Scale from 0.0 to 1.0

  int baseSpeed = 110;                 // Base forward speed
  int correction = multiplier * maxCorrection;

  int leftSpeed, rightSpeed;

  // Determine turn direction
  if (error > 0) {
    // Need to turn left → slow left motor
    leftSpeed = baseSpeed - correction;
    rightSpeed = baseSpeed;
  } else {
    // Need to turn right → slow right motor
    leftSpeed = baseSpeed;
    rightSpeed = baseSpeed - correction;
  }

  // Clamp motor speeds
  //leftSpeed = constrain(leftSpeed, 0, 255);
  //rightSpeed = constrain(rightSpeed, 0, 255);

  analogWrite(9, leftSpeed);   // Left motor
  analogWrite(10, rightSpeed); // Right motor

  Serial.print("Heading: "); Serial.println(heading);
  Serial.print("Error: "); Serial.println(error);
  Serial.print("Left Speed: "); Serial.println(leftSpeed);
  Serial.print("Right Speed: "); Serial.println(rightSpeed);
}

void releaseMotors() {
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);

  analogWrite(9, 0);
  analogWrite(10, 0);
}

void backward() {
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  
  analogWrite(9, 250);
  analogWrite(10, 250);
}

void forward() {
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
}

void turnright() {
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
}

void turnleft() {
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
}

void stopp() {
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
}
