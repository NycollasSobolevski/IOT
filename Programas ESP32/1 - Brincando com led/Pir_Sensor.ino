//Usando kit 7 de ESP32


int portas[] = {5,18,19,21};
#define potenciometro 4
#define PIR 23

void setup() {
  for(int i = 0; i < 4; i++){
   pinMode(portas[i],OUTPUT);
  }
  pinMode(4, INPUT);
  pinMode(PIR, INPUT);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(PIR)== HIGH){
      for(int i=0; i<4; i++)
        digitalWrite(portas[i], HIGH);
      delay(10);
      for(int i=0; i<4; i++)
        digitalWrite(portas[i], LOW);
  }
}
