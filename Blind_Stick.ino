#define trigPin 2
#define echoPin 3
#define buzzerPin 4
#define ledPin 5
#define vibPin 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}.

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Alert if obstacle detected
  if (distance > 0 && distance <= 70) { // within 70 cm
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(vibPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(vibPin, LOW);
    delay(100);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    digitalWrite(vibPin, LOW);
  }

  delay(50);
}



/*
Connections
1. Ultrasonic Sensor (HC-SR04) → Arduino Nano

VCC → 5V

GND → GND

Trig → D2

Echo → D3

2. Buzzer → Arduino Nano

Positive (+) → D4

Negative (-) → GND

3. LED → Arduino Nano

Positive (Anode) → D5 (through a 220Ω resistor)

Negative (Cathode) → GND


*/
