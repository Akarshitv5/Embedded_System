#include <Servo.h>                //Using the Arduino as the controller device,the library enables to control the servo motor
Servo myservo;                    //initialize a servo object to control a servo 

int pos = 0;                      //initization position of servo motor 
int trigPin = 3;                  //ultasonic trig pin is connected to pin 3 of Arduino Nano
int echoPin = 2;                  //ultasonic echo pin is connected to pin 2 of Arduino Nano

int duration;                     //integer duration is created for store the value from ultrasonic sensor 
int distance;                     //integer distance is created for store the value from ultrasonic sensor 

void setup() 
{
  Serial.begin(9600);             // Initiate a serial communication with baud rate of 9600
  myservo.attach(8);              // servo pin is connected to the pin 8 of arduino nano
  pinMode(trigPin, OUTPUT);       // select ultrasonic pin as a output pin
  pinMode(echoPin, INPUT);        //select ultrasonic pin as a input pin 
  myservo.write(pos);             //initial position of servo 
}


void loop() 
{ 
   ultrasonic();                  //calling ultrasonic function 
  if (distance < 27)              //condition applying 
    {
    myservo.write(pos+90);        //as per the readings of ultrasoinc sensor servo changes the pos 
   Serial.println(distance);     
   delay(1000);
  }
  else 
  {
      myservo.write(pos);        //as per the readings of ultrasoinc sensor servo changes the pos 
  }
  delay(300);
}

//Function for ultrasonic sensor  
void ultrasonic()
{
  digitalWrite(trigPin, LOW);      // Clears the trigPin condition
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);      // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);// Calculating the time
  distance = 0.034*(duration/2);   // Calculating the distance
                                       
}