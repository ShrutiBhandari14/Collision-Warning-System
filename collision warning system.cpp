const int trigPin = 7;
const int echoPin = 6;
#define buzzerpin 2
#define in_1 11
#define in_2 12
#define in_3 9
#define in_4 10
#define ledpin2 10
char a;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(in_1,OUTPUT);
  pinMode(in_2,OUTPUT);
  pinMode(in_3,OUTPUT);
  pinMode(in_4,OUTPUT);

  pinMode(ledpin2,OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  a=Serial.read();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if (a=='1'){
    digitalWrite(in_1, HIGH);
    digitalWrite(in_2, LOW);
    digitalWrite(in_3, LOW);
    digitalWrite(in_4, HIGH);
  }
  
  if(distance<=30 && distance>=7){  
  digitalWrite(ledpin2,HIGH);   
  digitalWrite(buzzerpin, HIGH);
  delay(100);
  digitalWrite(ledpin2,LOW);
  digitalWrite(buzzerpin, LOW);
  delay(100);
 
  }
  if(distance>=30 && distance<=70){
    digitalWrite(buzzerpin, HIGH);
    delay(100);
    digitalWrite(buzzerpin, LOW);
    delay(1000);
    
  }
  if(distance<7 && distance>=1){
    digitalWrite(ledpin2,HIGH);
    
    digitalWrite(in_1,LOW);
    digitalWrite(in_2,LOW);
    digitalWrite(in_3,LOW);
    digitalWrite(in_4,LOW);
  }
  else{
    digitalWrite(ledpin2, LOW);
    
    digitalWrite(buzzerpin, LOW);
  }

  }
