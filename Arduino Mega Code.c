/*
 greenLEDs[] = {24, 25, 30, 31};
 yellowLEDs[] = {26, 27, 32, 33};
 redLEDs[] = {28, 29, 34, 35};
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SCL, SDA pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);



#define NUM_SENSORS 4

int triggerPins[NUM_SENSORS] = {2, 4, 6, 8};
int echoPins[NUM_SENSORS] = {3, 5, 7, 9};

// Array to store the distances measured by each sensor
int distances[NUM_SENSORS];
int distance=0;
int RFID1=0,RFID2=0;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    pinMode(triggerPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
  for (int pin = 24; pin <= 35; pin++)
  {
    pinMode(pin, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
////////////////////////////////////////
 // Initialize OLED display with I2C addr 0x3C (for the 128x32)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 5);     // Start at top-left corner
  display.println(F("Intelligent Traffic"));
  display.setCursor(30, 15);     // Start at top-left corner
  display.println(F("Management"));
  display.display();
  delay(500);

  display.clearDisplay();
 
  display.setCursor(20, 10);    
  display.println(F("Team Members"));
  display.display();
  delay(500);
  display.clearDisplay();
  display.setCursor(10, 0);    
  display.println(F("Anurag S Nair"));
  display.setCursor(10, 10);    
  display.println(F("Ashiba Vijay"));
  display.setCursor(10, 20);    
  display.println(F("Sneha S"));
  display.display();
  delay(500);

///////////////////////////////////////

 
}

void loop() {
  rfidread();
 
  // Measure distance for each sensor
  for (int i = 0; i < NUM_SENSORS; i++) {
    distance = measureDistance(triggerPins[i], echoPins[i]);
    if (distance <= 20){distances[i]=0;}
    else{distances[i]=1;}
  }
 
  // Find minimum distance
  float minDistance = distances[0];
  int minSensor = 0;
  for (int i = 1; i < NUM_SENSORS; i++) {
    if (distances[i] < minDistance) {
      minDistance = distances[i];
      minSensor = i;
    }
  }
 
  // Check if two or more sensors have the same distance
  int equalSensors[NUM_SENSORS];
  int numEqual = 0;
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (distances[i] == minDistance) {
      equalSensors[numEqual] = i;
      numEqual++;
    }
  }
  if (numEqual == 1) {
    activateLED(minSensor+1);
  }
  else if (numEqual == 2) {
    for (int i = 0; i < numEqual; i++) {
      check(equalSensors[i]+1);
    }
  }
  else if (numEqual == 3) {
    for (int i = 0; i < numEqual; i++) {
      check(equalSensors[i]+1);
    }
  }
  else if (numEqual == 4) {
    for (int i = 0; i < numEqual; i++) {
      check(equalSensors[i]+1);
    }
  }
  delay(700); // Delay between measurements
}

int measureDistance(int triggerPin, int echoPin) {
  // Measure distance using ultrasonic sensor ,Send a 10us pulse to trigger the sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Measure the duration of the echo pulse
  unsigned long duration = pulseIn(echoPin, HIGH);
  // Calculate the distance based on the speed of sound (343m/s)
  // Distance = (duration * speed of sound) / 2
  int distance = (duration * 0.0343) / 2; // Distance in centimeters
  return distance;
}

void activateLED(int i) {
  if (i == 4)       ledBlink(24,29,34,35);
  else if (i == 3)  ledBlink(25,28,34,35);
  else if (i == 2)  ledBlink(30,28,29,35);
  else if (i == 1)  ledBlink(31,28,29,34);
}

void yellowLED(int i){
  if (i==4)       ledBlink(26,29,34,35);
  else if(i==3)   ledBlink(27,28,34,35);
  else if (i==2)  ledBlink(32,28,29,35);
  else if (i==1)  ledBlink(33,28,29,34);
}

void check(int s1){
  if (s1==11){
    activateLED(1); delay(5000);
    yellowLED(1); delay(200);
    }
  else if (s1==22){
  activateLED(2); delay(5000);
  yellowLED(2); delay(200);
    }
  else{
    activateLED(s1); delay(1000);
    yellowLED(s1); delay(200);
    rfidread();
    }
}

void ledBlink(int a,int b,int c,int d){
  for(int j=24;j<36;j++)
  {
    if(j==a || j==b || j==c || j==d)  digitalWrite(j, HIGH);
    else digitalWrite(j, LOW);
  }
}

void rfidread(){
  RFID1 = digitalRead(A0); // Read the analog value from pin A0
  RFID2 = digitalRead(A1); // Read the analog value from pin A0
  Serial.print("Analog Value: ");
  Serial.println(RFID1);
  if(RFID1==1)  check(11);
  else if (RFID2==1)  check(22);
  RFID1=0;RFID2=0;
   
}
