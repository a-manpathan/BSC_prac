#include <RTClib.h>

#include <Adafruit_Sensor.h>

#include <DHT.h>

#include <DHT_U.h>

#include <RTClib.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
int red = 6;
RTC_DS1307 rtc;

int temp_sum;
int hum_sum;
int counter;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHT"));
  pinMode(red, OUTPUT);
  dht.begin();
  rtc.begin();
  if (!rtc.isrunning()) {
    Serial.println(F("RTC is NOT running!"));
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

   if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
   }

    float hif = dht.computeHeatIndex(f, h);//heat index in fahrenheit
  float hic = dht.computeHeatIndex(t, h, false);//heat index celsius

   Serial.print(F(" "));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  

   digitalWrite(red, LOW);

  temp_sum += t;
  hum_sum += h;
  counter++;
  
  // Calculate average after 10 readings
  if (counter == 3) {
    float avg_temp = temp_sum / 3;
    float avg_hum = hum_sum / 3;
    
    // Print average values
    Serial.print("Average temperature: ");
    Serial.print(avg_temp);
    Serial.println(" °C");
    Serial.print("Average humidity: ");
    Serial.print(avg_hum);
    Serial.println(" %");
    
    // Reset variables
    counter = 0;
    temp_sum = 0;
    hum_sum = 0;
  }
  
  // Wait for 2 seconds before taking next reading
  delay(2000);

  if (h>50){
    digitalWrite(red,HIGH);
    }

   

}
