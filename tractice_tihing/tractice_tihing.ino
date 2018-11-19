//Motor Connections
//Change this if you wish to use another diagram
#define EnB  5
#define In3  7
#define In4  6
byte PWM_PIN = 3;
int pwm_value;
int motorSpeed;
void setup()
{
  // All motor control pins are outputs
  pinMode(PWM_PIN, INPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  Serial.begin(115200);
}



void loop()
{
 pwm_value = pulseIn(PWM_PIN, HIGH);
  //Serial.println(pwm_value);
  //Serial.println(pwm_value_L);
  if(pwm_value <1500 && pwm_value >1460){
    digitalWrite(In3, LOW);
     digitalWrite(In4, LOW); 
     motorSpeed = 0;
  }
  if(pwm_value >1550){
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    // set speed to 150 out 255
    
    motorSpeed = map(pwm_value,1470 ,1970 , 0, 255);
  }
 if(pwm_value< 1450){
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);

    motorSpeed = map(pwm_value,1550 ,990 , 0, 255);
 }
  
  analogWrite(EnB, motorSpeed);
  Serial.println(motorSpeed);
  Serial.println(pwm_value);
  
}
