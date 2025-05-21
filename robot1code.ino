#include <QMC5883L.h>
#include <Wire.h>

/////////////// compass
QMC5883L compass;
int16_t x, y, z, t;
float heading;
float targetHeading = 0; // Target heading to maintain straight line (0 degrees is straight)
///////////////

/////////////// Ultrasonic
#define echoPin 7
#define trigPin 8
long duration;
int fdistance;
int distance;
bool isfirst = true;
///////////////

/////////////// Speed
float speeed;
unsigned long timme1, prevtimme;
int ddistance, prevdistance, dtimme;
///////////////

/////////////// Infrared
int leftinf;
int rightinf;
///////////////

/////////////// Calibration
int16_t xMin = 32767, yMin = 32767;
int16_t xMax = -32767, yMax = -32767;
unsigned long calibrationStartTime;
bool calibrationDone = false;
///////////////

void setup() {
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.setSamplingRate(50);
}

void loop() {
  ///////////////////////////////////////////////////// calibration
  if (!calibrationDone) {
    calibrateCompass();
    if (millis() - calibrationStartTime > 10000) {
      calibrationDone = true;
      Serial.println("Calibration done.");
      Serial.print("xMin: "); Serial.println(xMin);
      Serial.print("xMax: "); Serial.println(xMax);
      Serial.print("yMin: "); Serial.println(yMin);
      Serial.print("yMax: "); Serial.println(yMax);
    }
  } else {
    ////////////////////////////////////////////

    ///////////////////////////
    comp(); // Get the compass reading
    ultrasonic();
    infrared();
    serials();
    decisionfunctoin();
    motor();
    speedfun();
    /////////////////////////
  }
}

//////test
