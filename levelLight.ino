const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

#define BLUE 3
#define GREEN 5
#define RED 6

#define delayTime 25

int brightness = 255;

void setup() {
  Serial.begin(115200);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
}

void increaseBrightness() {
  if (brightness < 255) {
    brightness += 1;
  }
}

void decreaseBrightness() {
  if (brightness > 0) {
    brightness -= 1;
  }
}

void updateColour() {
  analogWrite(RED, brightness);
  analogWrite(GREEN, brightness);
  analogWrite(BLUE, brightness);
}

void loop() {
  
  int x = analogRead(X_pin);
  Serial.print(x);
  Serial.print("\n");
  if (x > 600) {
    increaseBrightness();
  } 
  else if (x < 300) {
    decreaseBrightness();
  }
  updateColour();
  delay(delayTime);
}
