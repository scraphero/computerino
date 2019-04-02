#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  lcd.clear();
  //lcd.backlight();    //retroiluminacion activada
  lcd.noBacklight();  //sin retroiluminacion
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  
}

void loop() {

}
