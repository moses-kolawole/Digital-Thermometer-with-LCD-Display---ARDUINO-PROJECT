#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <DHT.h>

int sda = A4;
int scl = A5;

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);
float temperature;
float humidity;
int delay_time = 1000;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
lcd.begin(16, 2);
lcd.backlight();
}


void loop(){

temperature = dht.readTemperature();

if(isnan(temperature)){
  lcd.setCursor(4, 0);
  lcd.print("NAN");
  delay(delay_time);
  lcd.clear();
}SS

lcd.setCursor(0, 0);
lcd.print("Temperature is ");
lcd.setCursor(3, 1);
lcd.print(temperature);
delay(delay_time);
lcd.clear();
}
