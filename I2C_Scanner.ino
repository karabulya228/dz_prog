#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Begin scan");

  for (uint8_t addr = 1; addr <= 127; addr++) {
    Wire.beginTransmission(addr);
    if (!Wire.endTransmission()) {
      Serial.print("0x");
      Serial.println(addr, HEX);
    }
  }

  Serial.println("End scan");
  Serial.println();
  delay(1000);
}
