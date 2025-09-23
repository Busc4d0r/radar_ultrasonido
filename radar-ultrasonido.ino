#include <Servo.h>
const int trigger = A1;
const int echo = A0;
const int indicador = LED_BUILTIN;
long duracion;
int distancia;
Servo myServo;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(indicador, OUTPUT);
  Serial.begin(9600);
  myServo.attach(12);
}

void loop() {
  for(int i=15;i<=165;i++){
    myServo.write(i);
    delay(30);
    distancia = calcularDistancia();
    if (distancia < 40) digitalWrite(indicador, HIGH);
    else if(distancia > 40) digitalWrite(indicador, LOW);
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
 
  for(int i=165;i>15;i--){
    myServo.write(i);
    delay(30);
    distancia = calcularDistancia();
    if (distancia < 40) digitalWrite(indicador, HIGH);
    else if(distancia > 40) digitalWrite(indicador, LOW);
    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}

int calcularDistancia(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = (duracion*0.0343)/2;
  return distancia;
}