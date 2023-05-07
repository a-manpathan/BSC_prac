int trig=12;
int echo=13;
long duration;
int distance;
int dist_sum;
int counter;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  delay(200);


  dist_sum += distance;
  counter++;
  
  // Calculate average after 10 readings
  if (counter == 3) {
    float avg_dist = dist_sum / 3;

    
    // Print average values
    Serial.print("Average Distance: ");
    Serial.print(avg_dist);
    Serial.println(" %");
    
    // Reset variables
    counter = 0;
    dist_sum = 0;
  }

}
