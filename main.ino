
const int fwdLMotorPin = 5;
const int fwdRMotorPin = 6;

const int bkLMotorPin = 3;
const int bkRMotorPin = 9;

const int LlineTrasePins[3] = {A0, A1, A2};
const int RlineTrasePins[3] = {A3, A4, A5};

int RlineTraseVals[3];
int LlineTraseVals[3];

int motorVols[4];

bool isAdjMode = false;

void setup() {
  //INITIALIZE

  //LINE TRASE SENSOR
  for(int i=0;i<3;i++){
    pinMode(LlineTrasePins[i], INPUT);
    pinMode(RlineTrasePins[i], INPUT);
  }

  //MOTOR SOURCE
  pinMode(fwdLMotorPin, OUTPUT);
  pinMode(fwdRMotorPin, OUTPUT);
  pinMode(bkLMotorPin, OUTPUT);
  pinMode(bkRMotorPin, OUTPUT);

  if(isAdjMode){
    Serial.begin(9600);
    Serial.print("This is Adjusting Mode");
    
    analogWrite(fwdLMotorPin, 0);
    analogWrite(fwdRMotorPin, 0);
    analogWrite(bkLMotorPin, 0);
    analogWrite(bkRMotorPin, 0);
 
  }
}

void loop() {
  if(isAdjMode){
    /*
    for(int i=0;i<3;i++){
      Serial.print("L line trase pin num");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print(analogRead(LlineTrasePins[i]));
      Serial.print("\n");
      Serial.print("R line trase pin num");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print(analogRead(RlineTrasePins[i]));
      Serial.print("\n");
      delay(500);
    }
    */
    Serial.print("Center pin ");
    Serial.print("R");
    Serial.print(" : ");
    Serial.print(analogRead(LlineTrasePins[2]));
    Serial.print("\n");
    Serial.print("L");
    Serial.print(" : ");
    Serial.print(analogRead(LlineTrasePins[1]));
    Serial.print("\n");

  } else {
    /*
    analogWrite(fwdLMotorPin, 200);
    delay(50);
    analogWrite(fwdLMotorPin, 0);
    analogWrite(fwdRMotorPin, 100);
    delay(50);
    analogWrite(fwdRMotorPin, 0);
    */

    if(analogRead(RlineTrasePins[0]) > 300 && analogRead(LlineTrasePins[2]) > 300){
      //真ん中に黒線がある
      analogWrite(fwdLMotorPin, 150);
      analogWrite(fwdRMotorPin, 150);
      analogWrite(bkLMotorPin, 0);
      analogWrite(bkRMotorPin, 0);
    } else if(analogRead(RlineTrasePins[0]) > 300 && analogRead(RlineTrasePins[1]) > 300){
      analogWrite(fwdLMotorPin, 0);
      analogWrite(fwdRMotorPin, 170);
      analogWrite(bkLMotorPin, 170);
      analogWrite(bkRMotorPin, 0);

    } else if(analogRead(LlineTrasePins[2]) > 300 && analogRead(LlineTrasePins[1]) > 300){
      analogWrite(fwdLMotorPin, 170);
      analogWrite(fwdRMotorPin, 0);
      analogWrite(bkLMotorPin, 0);
      analogWrite(bkRMotorPin, 170);
    }
  }
}