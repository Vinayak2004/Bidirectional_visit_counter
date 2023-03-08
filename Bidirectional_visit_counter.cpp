
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 7,6,5,4);

#define in 8
#define out 9
#define led 13

int count = 0;
int count1=0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(led, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0, 1);
  lcd.print(count);
}

void loop() {
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if (in_value == LOW && out_value == HIGH) {
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(1000);
  }

  if (out_value == LOW && in_value == HIGH) {
    count1 = count-1;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count1);
    delay(1000);
  }


  if (count1 <= 0) {
    lcd.clear();
    digitalWrite(led, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0, 1);
    lcd.print("Light is Off");
    delay(200);
  }

  else {
    digitalWrite(led, HIGH);
  }
}