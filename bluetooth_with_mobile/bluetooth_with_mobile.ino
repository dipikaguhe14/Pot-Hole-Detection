
 int triggerPin = 7; //triggering on pin 7
int echoPin = 8;    //echo on pin 8
int LED = 13; //led pin
int info = 0;//variable for the information comming from the bluetooth module
int state = 0;//simple variable for displaying the state

void setup() { //we will be combinig both setups from the codes

  Serial.begin(9600);  //we'll start serial comunication, so we can see the distance on the serial monitor
  
  pinMode(triggerPin, OUTPUT); //defining pins
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);    //defining LED pin
  digitalWrite(LED, LOW);  //once the programm starts, it's going to turn of the led, as it can be missleading.
  
}

void loop(){ //here we combine both codes to work in the loop
 
 sensor();
 
}

void sensor(){
  int duration, distance;    //Adding duration and distance
  
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
 Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line

  if(distance>=20)
  {
    Serial.println("pot hole detected...");
   
    delay(2000);
    }
    
  }
    


