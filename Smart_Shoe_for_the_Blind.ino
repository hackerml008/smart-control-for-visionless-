const int trigPin = 9;  
const int echoPin = 10;
const int vibratorPin = 11;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(vibratorPin, OUTPUT);
  analogWrite(vibratorPin, 0);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  val = map(distance,0,20,200,0);
  val = constrain(val,0,200);
  analogWrite(vibratorPin, val);
}