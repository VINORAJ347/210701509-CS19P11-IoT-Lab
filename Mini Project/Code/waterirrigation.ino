const int sensorPin= A0;
const int buzz=7;
const int sense=2;
const int relay=8;
int watervalue=0;
int sensorValue=0;
int Led=13;
void setup() {

  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Led,OUTPUT);
pinMode(buzz,OUTPUT);
pinMode(sense,INPUT);
pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue=analogRead(sensorPin);
watervalue=digitalRead(sense);

Serial.print("Soil moist Level: ");
Serial.println(sensorValue);
if(watervalue==LOW){
  digitalWrite(buzz,HIGH);
}
else{
  digitalWrite(buzz,LOW);
}

if(sensorValue>=900){
  Serial.println("Irrigation OFF");
  digitalWrite(Led,HIGH);
  digitalWrite(relay,LOW);
}
if(sensorValue<=450){
  Serial.println("Irrigation ON");
  digitalWrite(Led,LOW);
  digitalWrite(relay,HIGH);
   }
  delay(500);
}
