
#include <BluetoothSerial.h>
const int bedroomBulb = 25;
const int securityBulb = 13;
const int sittingroomBulb = 27;
const int kitchenBulb = 5;
const int sensorPin = 2;
int lightInit;
int lightVal;

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  Serial.println("SMART HOME LIGHTING SYSTEM.");
  
  SerialBT.begin("SMARTHOME");
  
  pinMode(bedroomBulb,OUTPUT);
  pinMode(securityBulb,OUTPUT);
  pinMode(sittingroomBulb,OUTPUT);
  pinMode(kitchenBulb,OUTPUT);

  lightInit = analogRead(sensorPin);
  Serial.println(lightInit);
  
  
  
  digitalWrite(bedroomBulb,LOW);
  digitalWrite(securityBulb,LOW);
  digitalWrite(sittingroomBulb,LOW);
  digitalWrite(kitchenBulb,LOW);
  
  
}

void loop() {

  lightVal = analogRead(sensorPin);
  Serial.println(lightVal);
  delay(1000);

  if(lightVal - lightInit < 50){
    digitalWrite(securityBulb,HIGH);
  }
  else
  {
    digitalWrite(securityBulb,LOW);
  }
  
  if(SerialBT.available()){
    int x = SerialBT.read();
    
    if(x == '1'){
      digitalWrite(bedroomBulb,HIGH);
      Serial.println("Bedroom Bulb ON");}
    if(x == '2'){
       digitalWrite(bedroomBulb,LOW);
      Serial.println("Bedroom bulb OFF");
      }
    if(x == '3'){
      digitalWrite(securityBulb,HIGH);
      Serial.println("Security Bulb ON");}
    if(x == '4'){
       digitalWrite(securityBulb,LOW);
      Serial.println("Security bulb OFF");
    }
    if(x == '5'){
      digitalWrite(sittingroomBulb,HIGH);
      Serial.println("Sitting Room Bulb ON");}
    if(x == '6'){
       digitalWrite(sittingroomBulb,LOW);
      Serial.println("Sitting Room bulb OFF");
    }
    if(x == '7'){
      digitalWrite(kitchenBulb,HIGH);
      Serial.println("Kitchen Bulb ON");}
    if(x == '8'){
       digitalWrite(kitchenBulb,LOW);
      Serial.println("Kitchen bulb OFF");
    }
  }
      
  }
