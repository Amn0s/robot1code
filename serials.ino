void serials()
{
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("  ");
  Serial.print(fdistance);
  Serial.print(" cm");
  Serial.print("  ");  
  Serial.print("li=");
  Serial.print(leftinf);
  Serial.print("  ");
  Serial.print("ri=");
  Serial.print(rightinf);
  Serial.print("  ");
  Serial.print("heading= ");
  Serial.print(heading);
  Serial.print("   ");
  //Serial.print(sheading);
  if(distance>30){Serial.print("    forward");}
  if(distance<30){Serial.print("    stop");}
  Serial.print("  ");
  Serial.print("speed= ");
  Serial.print(speeed);
  Serial.print("   ddistance= ");
  Serial.print(ddistance);
  Serial.print("   dtime= ");
  Serial.print(dtimme);
  Serial.println();
}
