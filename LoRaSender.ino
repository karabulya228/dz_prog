#include <SPI.h>
#include <LoRa.h>
#define ss 4
#define reset 2
#define dio0 3
int counter = 0;

void setup() {
  Serial.begin(115200);
  LoRa.setPins(ss,reset,dio0);
 
  while (!Serial);

  Serial.println("LoRa Sender");

  while(!LoRa.begin(433E6)) {
    LoRa.begin(433E6);
    delay(2000);
  }
  
  
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
