int lowPulseLength = 4000;
int highPulseLength = 0;
int measuredLength = 0;
int doonce = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  Serial.begin(57600);
}

void loop() {
  if(doonce == 1){
    doonce = 0;
    delay(4000);
  }
  // put your main code here, to run repeatedly:
  measuredLength = pulseIn(7, HIGH);
  lowPulseLength = min(measuredLength, lowPulseLength);
  highPulseLength = max(measuredLength, highPulseLength);
  measuredLength = pulseIn(6, HIGH);
  lowPulseLength = min(measuredLength, lowPulseLength);
  highPulseLength = max(measuredLength, highPulseLength);
  measuredLength = pulseIn(7, HIGH);
  measuredLength = pulseIn(7, LOW);
  delay(100);
  Serial.print(lowPulseLength);
  Serial.print(", ");
  Serial.print(highPulseLength);
  Serial.print(", ");
  Serial.println(measuredLength);

}
