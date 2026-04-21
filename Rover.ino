//motor and sonar pin definition
//motor1 being high and motor2 being low will cause the rover to move forward, vice versa for reverse
#define left_motor1 11
#define left_motor2 10
#define right_motor1 7
#define right_motor2 8
#define sonar_trig 4
#define sonar_echo 3

//movement and turning time in milliseconds. will change when testing in maze 
const int forward_time = 1000;
const int turn90time = 400;
const int turn180time = 800;
//change above constants later

void setup() {
  // put your setup code here, to run once:
  pinMode(left_motor1, OUTPUT);
  pinMode(left_motor2, OUTPUT);
  pinMode(right_motor1, OUTPUT);
  pinMode(right_motor2, OUTPUT);
  pinMode(sonar_trig, OUTPUT);
  pinMode(sonar_echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  rotate90left();
  forward();
  rotate90left();
  forward();
  rotate90left();
  forward();
  rotate180();
  delay(500);
  forward();
  rotate90right();
  forward();
  rotate90right();
  forward();
  rotate90right();
  forward();
  rotate180();
  delay(500);

}

//will turn the rover 90 degrees to its left on the spot
void rotate90left() {
  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(200);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, HIGH);
  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);
  delay(turn90time);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(500);
}

void rotate90right() {
  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(200);

  digitalWrite(left_motor1, HIGH);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, HIGH);
  delay(turn90time);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(500);
}

void rotate180() {
  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(200);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, HIGH);
  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);
  delay(turn180time);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(500);
}

void forward() {
  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(200);

  digitalWrite(left_motor1, HIGH);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);
  delay(forward_time);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  delay(500);
}
