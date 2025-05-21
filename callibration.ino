void calibrateCompass() {
  compass.readRaw(&x, &y, &z, &t);

  if (x < xMin) xMin = x;
  if (x > xMax) xMax = x;
  if (y < yMin) yMin = y;
  if (y > yMax) yMax = y;
}
