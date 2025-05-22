#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

String timeStr = "";
String dateStr = "";

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Waiting for time");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    int sep = input.indexOf('|');

    if (sep > 0) {
      timeStr = input.substring(0, sep);
      dateStr = input.substring(sep + 1);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time: " + timeStr);
      lcd.setCursor(0, 1);
      lcd.print("Date: " + dateStr);
    }
  }
}
