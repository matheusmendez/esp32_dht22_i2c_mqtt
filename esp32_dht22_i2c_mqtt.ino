// https://github.com/marcoschwartz/LiquidCrystal_I2C/archive/master.zip
// https://github.com/winlinvip/SimpleDHT/archive/refs/heads/master.zip

#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>
//#include "MQTT_Client.h"
// CONSTANTS
#define LCD_COLUMNS 16
#define LCD_ROWS  2
#define LCD_ADDRESS 0x27
#define DHT22 4


// VARS
float temp, humi;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
SimpleDHT22 dht22(DHT22);

//PROTOTYPE
void setup_lcd(void);
void print_lcd(void);
void read_sensor(void);

void setup(){
  setup_lcd();
}

void loop(){
  read_sensor();
  print_lcd();
  delay(2500);
}


void setup_lcd(void)
{
    Serial.begin(115200);
    // initialize LCD
    lcd.init();
    // turn on LCD backlight                      
    lcd.backlight();
}

void print_lcd(void)
{
  // clears the display to print new message
  lcd.clear();
   // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Temp:" + String(temp) +"\xDF" + "C");
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Humi:" + String(humi) +"%");
}

void read_sensor(void)
{
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&temp, &humi, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err));
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print((float)temp); Serial.print(" °C, ");
  Serial.print((float)humi); Serial.println(" RH%");
}
