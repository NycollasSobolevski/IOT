void Efeito1(int QTD_LED, int LEDlist[], int timer){
  void loop(){
    for(int i=0; i<QTD_LED;i++)
    digitalWrite(LEDlist[i], HIGH);
    delay(timer);
    digitalWrite(LEDlist[i], LOW);

    if(digitalRead(button) == HIGH)
      exit(0);
  }
}
