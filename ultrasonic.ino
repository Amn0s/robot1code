

void ultrasonic()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  timme1=millis();
  dtimme=timme1-prevtimme;
  prevtimme=timme1;
  distance = duration * 0.034 / 2; 
  ddistance = abs(prevdistance-distance);
  prevdistance=distance;
  if (isfirst){
    fdistance = distance;
    isfirst = false ;
    }
  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  
  
}
