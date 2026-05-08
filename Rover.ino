#define left_motor1 11
#define left_motor2 10
#define right_motor1 7
#define right_motor2 8

#define sonar_trig 4
#define sonar_echo 3

// settings


// cell movement time
const int cell_time = 1200;

// turning times
const int turn90time = 400;
const int turn180time = 4350;

// distance to wall
const int wall_distance = 15; // cm


void setup() {

  pinMode(left_motor1, OUTPUT);
  pinMode(left_motor2, OUTPUT);

  pinMode(right_motor1, OUTPUT);
  pinMode(right_motor2, OUTPUT);

  pinMode(sonar_trig, OUTPUT);
  pinMode(sonar_echo, INPUT);

  Serial.begin(9600);
}


void loop() {

  mazeLogic();

}

// maze
void mazeLogic() {

  int frontDistance = getDistance();

  Serial.print("Front Distance: ");
  Serial.println(frontDistance);

  if (frontDistance > wall_distance) {

    moveOneCell();

  }

// check left
  else {

    stopMotors();
    rotate90left();

    int leftDistance = getDistance();

    Serial.print("Left Distance: ");
    Serial.println(leftDistance);

    if (leftDistance > wall_distance) {

      moveOneCell();

    }

// check right
    else {

      rotate90right();
      stopMotors();
      delay(200);
      rotate90right();

      int rightDistance = getDistance();

      Serial.print("Right Distance: ");
      Serial.println(rightDistance);


      if (rightDistance > wall_distance) {

        moveOneCell();

      }

      else {

        rotate180();
        moveOneCell();

      }
    }
  }
}

// SONAR 

int getDistance() {

  digitalWrite(sonar_trig, LOW);
  delayMicroseconds(2);

  digitalWrite(sonar_trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(sonar_trig, LOW);

  long duration = pulseIn(sonar_echo, HIGH);


  int distance = duration * 0.034 / 2;

  return distance;
}


// MOVEMENT 

void stopMotors() {

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW);

  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
}

void moveOneCell() {

  stopMotors();
  delay(200);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, HIGH);

  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, HIGH);

  delay(cell_time);

  stopMotors();
  delay(300);
}


void rotate90right() {

  stopMotors();
  delay(200);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, HIGH);

  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);

  delay(turn90time);

  stopMotors();
  delay(300);
}


void rotate90left() {

  stopMotors();
  delay(200);

  digitalWrite(left_motor1, HIGH);
  digitalWrite(left_motor2, LOW);

  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, HIGH);

  delay(turn90time);

  stopMotors();
  delay(300);
}


void rotate180() {

  stopMotors();
  delay(200);

  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, HIGH);

  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);

  delay(turn180time);

  stopMotors();
  delay(300);
}
