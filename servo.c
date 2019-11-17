#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <DS3231.h>
#include <Servo.h>


// Relay 1 - PIN6
int Relay = 6;
// Relay 2 - PIN7
int Relay2 = 7;

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
Servo servo_9;



DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 14;
const int OnMin = 12;
const int OffHour = 14;
const int OffMin = 13;
const int OnHour2 = 14;
const int OnMin2 = 14;
const int OffHour2 = 14;
const int OffMin2 = 15;
const int OnHour3 = 14;
const int OnMin3 = 16;
const int OffHour3 = 14;
const int OffMin3 = 17;
void setup() {
  Serial.begin(115200);
  rtc.begin();
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(6, LOW);
  digitalWrite(7, LOW);


  servo_9.attach(9); // init pin
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.print(t.sec);
  Serial.print(" sec(s)");
  Serial.println(" ");
  delay (1000);
  
  if((t.hour == OnHour && t.min == OnMin) || 
     (t.hour == OnHour2 && t.min == OnMin2) ||
     (t.hour == OnHour3 && t.min == OnMin3)){
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    servo_9.write(45); // write to servo
    Serial.println("Den gio an");
    }
    
  else if((t.hour == OffHour && t.min == OffMin) ||
          (t.hour == OffHour2 && t.min == OffMin2)||
          (t.hour == OffHour3 && t.min == OffMin3)
  ){
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      servo_9.write(0); // write to servo
      Serial.println("Het gio an");
    }


    servo_9.write(45); // write to servo
    _delay(1);
    servo_9.write(0); // write to servo
    _delay(1);
    
    _loop(1);


}



void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}
