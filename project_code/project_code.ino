//Motor Connections
//Change this if you wish to use another diagram
#define EnA  10
#define In3  6
#define In4  7
byte PWM_PIN = 3;
int motorSpeedA = 0;
 
 
void setup()
{
  // All motor control pins are outputs
  pinMode(PWM_PIN, INPUT);
  pinMode(EnA, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int xAxis = analogRead(A1);
  Serial.println(xAxis);
}
