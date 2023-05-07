int red = 13;
int red2 = 12;

int green = 11;
int green2 = 10;

int blue = 9;
int blue2 = 8;
void setup() {
  // put your setup code here, to run once:
    pinMode(red, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(blue2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(red, LOW);
   digitalWrite(red2, LOW);
   digitalWrite(green, LOW);
   digitalWrite(green2, LOW);
   digitalWrite(blue, LOW);
   digitalWrite(blue2, LOW);


   for (int i = 0; i < 2; i++) {
    // Blink the red LEDs
    digitalWrite(red, HIGH);
    //delay(500);
    //digitalWrite(red, LOW);
    digitalWrite(red2, HIGH);
    delay(500);
    digitalWrite(red2, LOW);
    digitalWrite(red, LOW);

    // Blink the green LEDs
    digitalWrite(green, HIGH);
    //delay(500);
    //digitalWrite(green, LOW);
    digitalWrite(green2, HIGH);
    delay(500);
    digitalWrite(green2, LOW);
    digitalWrite(green, LOW);

    // Blink the blue LEDs
    digitalWrite(blue, HIGH);
    //delay(500);
    //digitalWrite(blue, LOW);
    digitalWrite(blue2, HIGH);
    delay(500);
    digitalWrite(blue2, LOW);
    digitalWrite(blue, LOW);
  }

   

}
