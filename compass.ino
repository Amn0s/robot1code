void comp() {
  compass.readRaw(&x, &y, &z, &t);

  // حذف آفست‌های کالیبراسیون
  float xOffset = (xMax + xMin) / 2.0;
  float yOffset = (yMax + yMin) / 2.0;

  float xCal = x - xOffset;
  float yCal = y - yOffset;

  heading = atan2(yCal, xCal) * 180.0 / PI;
  if (heading < 0) heading += 360.0;

  Serial.print("Heading: ");
  Serial.println(heading);
}
