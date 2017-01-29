bool s1=false;//Si is checks if sensor i is getting white
bool s2=false;
bool s4=false;//S4 = Central Sensor
int s1pin=A0;
int s2pin=A2;
int s4pin=A1;
int leftWheelForward=5;
int rightWheelForward=2;
int leftWheelBackward=4;
int rightWheelBackward=3;

void updateSi(){
  s1 = analogRead(s1pin)<70;//Value for TinkerersLab1-70,keep 350 , 100 for debugging , 400-500 is also fine
  s2 = analogRead(s2pin)<200;//Value for TinkerersLab1-150; 200-250
  s4 = analogRead(s4pin)<400;//Value for TinkerersLab1-400
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(s1pin,INPUT);
  pinMode(s2pin,INPUT);
  //THIS ONE ISN"T GREAT -> pinMode(s3pin,INPUT);
  pinMode(s4pin,INPUT);
  pinMode(leftWheelForward,OUTPUT);
  pinMode(leftWheelBackward,OUTPUT);
  pinMode(rightWheelForward,OUTPUT);
  pinMode(rightWheelBackward,OUTPUT);
  allLow();
}

void allLow(){
  digitalWrite(leftWheelForward,LOW);
  digitalWrite(leftWheelBackward,LOW);
  digitalWrite(rightWheelForward,LOW);
  digitalWrite(rightWheelBackward,LOW);
}

void forward(int del){
  digitalWrite(leftWheelForward, HIGH );           
  digitalWrite(leftWheelBackward, LOW);
  digitalWrite(rightWheelForward, HIGH);
  digitalWrite(rightWheelBackward, LOW);
  delay(del);
  allLow();
}

void turnLeft(){
  digitalWrite(leftWheelForward, LOW);
  digitalWrite(leftWheelBackward, HIGH);
  digitalWrite(rightWheelForward, HIGH);
  digitalWrite(rightWheelBackward, LOW);
  delay(50);
  allLow();
}

void turnRight(){
  digitalWrite(leftWheelForward, HIGH);
  digitalWrite(leftWheelBackward, LOW);
  digitalWrite(rightWheelForward, LOW);
  digitalWrite(rightWheelBackward, HIGH);
  delay(50);
  allLow();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateSi();//update sensor values
  if(s1&&s2&&s4){
    forward(20);
  }
  else if(s2&&!s1){
    turnRight();
  }
  else if(s1&&!s2){
    turnLeft();
  }
  else{
    forward(20);
  }
  delay(15);
}
