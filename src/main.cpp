#include <Arduino.h>
#include <SSD1306.h>

SSD1306   display(0x3c, 4, 5, GEOMETRY_128_32);
int val = 0; // AD 변환값을 저장할 변수

void setup() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.drawString(10, 10, "Hello World");
  display.display();
  Serial.begin(115200);
  
}

void loop() {
  val = analogRead(0);
  delay(1000);
  display.clear();
  display.drawString(10, 10, String(val));
  display.display();
}
