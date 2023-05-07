#include <Servo.h>
Servo s;


void setup() {
  s.attach(7);
  
  // put your setup code here, to run once:

}

void loop() {
  
  for(int i=0; i<=180;i+=1){
    s.write(i);
    delay(50);
   }
   for (int i=180; i>=0; i-=1){
    s.write(i);
    delay(50);
    }
  
  // put your main code here, to run repeatedly:

}
