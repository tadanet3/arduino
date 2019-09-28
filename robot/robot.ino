/*
 * ロボットプログラミング
 */

#define trigPin 13
#define echoPin 12

#define motorA1 8
#define motorA2 9
#define motorAp 10
#define motorB1 7
#define motorB2 6
#define motorBp 5
#define STBY 11

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode( motorA1, OUTPUT );
  pinMode( motorA2, OUTPUT );
  pinMode( motorAp, OUTPUT );
  pinMode( motorB1, OUTPUT );
  pinMode( motorB2, OUTPUT );
  pinMode( motorBp, OUTPUT );
  pinMode( STBY, OUTPUT );

  digitalWrite( motorA1, LOW );
  digitalWrite( motorA2, LOW );
  digitalWrite( motorAp, LOW );
  digitalWrite( motorB1, LOW );
  digitalWrite( motorB2, LOW );
  digitalWrite( motorBp, LOW );
  digitalWrite( STBY, HIGH );

  Serial.begin(9600);
  Serial.println( "発射します、ご注意下さい。");
  delay( 1000 );
}

void loop() {
  long distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH) / 58.2;
  
  if (distance >= 10) {
    Serial.println("遠いので、前進します。");
    digitalWrite( motorAp, HIGH );
    digitalWrite( motorA1, HIGH );
    digitalWrite( motorA2, LOW );
    digitalWrite( motorBp, HIGH );
    digitalWrite( motorB1, HIGH );
    digitalWrite( motorB2, LOW );
  }
  else if (distance < 10 && distance > 2) {
    Serial.println("近いので、停止します。");
    digitalWrite( motorAp, LOW );
    digitalWrite( motorBp, LOW );
  } else {
    Serial.println("当たるので、後進します。");
    digitalWrite( motorAp, HIGH );
    digitalWrite( motorA1, LOW );
    digitalWrite( motorA2, HIGH );
    digitalWrite( motorBp, HIGH );
    digitalWrite( motorB1, LOW );
    digitalWrite( motorB2, HIGH );
  }
  delay( 1000);
}
