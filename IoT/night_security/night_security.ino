int ldr=A1;
int led=13;
int pin=3; //pir
int thr=10; //threshold
int value=0;
int pirState=LOW;
//int buz=7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(pin,INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int data=analogRead(ldr);
  value=digitalRead(pin);
  //Serial.println(data);
  delay(2);
  if (data<thr){
    //digitalWrite(led,HIGH);
    
  }
  else{
    //digitalWrite(led,LOW);
  }
  if (value==HIGH && pirState==LOW){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    Serial.println("Motion detected");
      Serial.println(value);
      pirState=HIGH;
    
  }else{
    digitalWrite(led,LOW);

    if(pirState==HIGH){
      Serial.println("Motion stopped");
      Serial.println(value);
      pirState=LOW;
    }
  }
  Serial.println(pirState);
  delay(3000);
  
}
