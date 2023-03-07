//Usando kit 7 de ESP32


int portas[] = {5,18,19,21};
#define potenciometro 4
#define PIR 23

void setup() {
  for(int i = 0; i < 4; i++){
   pinMode(portas[i],OUTPUT);
  }
  pinMode(4, INPUT);
  Serial.begin(9600);
}

int i = 0;
int temp = 0;
char direc ='l';


void loop() {
  temp = analogRead(4);
  if(temp < 7)
    temp = 7;
  Serial.println(temp);

  if(i == 3){
    direc = 'l';
  }
  if(i == 0){
    direc = 'r';
  }
  digitalWrite(portas[i], HIGH);
  delay(temp);
  digitalWrite(portas[i], LOW);
  if(direc == 'l')
    i--;
  else if(direc == 'r')
    i++;
}
