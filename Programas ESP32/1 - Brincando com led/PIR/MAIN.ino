int portas[] = {5,18,19,21};
#define potenciometro 4
#define PIR 23
#define button 2

void setup() {
  for(int i = 0; i < 4; i++){
   pinMode(portas[i],OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

int timer = 0;

void loop(){
  digitalWrite(portas[0], HIGH);
  delay(500);
  digitalWrite(portas[0], LOW);

  timer = digitalRead(potenciometro);
  if(timer < 7)
    timer = 7;
    
  if(digitalRead(button) == HIGH){
    Efeito1(4, portas, timer);
  }
}
