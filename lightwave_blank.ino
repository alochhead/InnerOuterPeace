/* 
Title: Inner Outer Peace
This is a code logic for a breathing pattern light that is meant to use a wearble belt sensor that tracks data and then displays 
the data in a progressive light pattern that resembles a wave. 

Written by
  Amelia Lochhead 
Referenced content from:
  Nick Puckett and Kate Hartman DIGF - Creation and Computation 
  https://docs.arduino.cc/language-reference
*/

int const sensorPin  = A0;
int const amountOfLights = 4;

int lightPins[amountOfLights];

void setup() {
  //Create communnication to serial USB drive 
  Serial.begin(9600);

  //This for loop sest up the light pins as an array of outpus 
  for(int i = 0; i < amountOfLights; i++){
    lightPins[i] = i+2; 
    // Adding lights to the array, starting point is D2
    pinMode(i, OUTPUT);
    // Making them outputs to be read 
  }
  //Testing: Serial.println(lightPins[amountOfLights]);

  //Initalizing sensor pin as input 
  pinMode(sensorPin, INPUT);

  constrain(0, 900, 1050);
  //Testing: Serial.print(sensorPin);
}

void loop() {

// Read sensor data in the loop function so it updates continuously 
int pressureValue = analogRead(sensorPin);
pressureValue = constrain(pressureValue, 900, 1050);

//Map the sensor data to the number of lights in the wave, starting from the bottom going up to top of wave 
int waveLights = map(pressureValue, 0, 700, 0, amountOfLights);

//By walking through a loop that is the length of the lights, light up leds 1 by 1 reletive to the map 
for(int i = 0; i < amountOfLights; i++){
  if (i < waveLights){
    digitalWrite(lightPins[i], HIGH); 
  }
  else{
    digitalWrite(lightPins[i], LOW); 
  }
}
  // Print data 
  Serial.print("Pressure value: " + pressureValue);
  Serial.print(" Amount of current: " + waveLights);
  Serial.println();

}
