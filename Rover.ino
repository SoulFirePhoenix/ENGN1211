// Pin allocations
// Pin  ( 2,3 are for Motor Left ) ( 4,5 are for Motor Right )


void setup() {
  // Motor Pin Def
  // Left
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Right
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


//Function Defs

// Steering Rover Control
void Left_Turn() {
  // Left
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
    
  // Right
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Right_Turn() {
  // Left
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  
  // Right
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void Forward() {
  // Left
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

  // Right
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Backward() {
    // Left
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  // Right
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}



void loop() {
  // put your main code here, to run repeatedly:


}
