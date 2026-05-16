// ESP32 Smart Lock (Conceptual Logic)

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String password = "1234";
String input = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Enter Password");
}

void loop() {
  char key = getKeypadInput();  // assume function for keypad input

  if (key) {
    input += key;
    lcd.setCursor(0, 1);
    lcd.print(input);

    if (input.length() == 4) {
      if (input == password) {
        lcd.clear();
        lcd.print("Access Granted");
        // digitalWrite(RELAY, HIGH);
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
      }
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password");
      input = "";
    }
  }
}

// Dummy keypad function (for representation)
char getKeypadInput() {
  return 0;
}
