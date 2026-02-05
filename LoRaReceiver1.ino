#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <LCDI2C_Multilingual_MCD.h>
#define ss 16
#define reset 2
#define dio0 15
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
//LCDI2C_Generic lcd(0x27,16,2);

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire);

void drawText( String displayText){
  display.clearDisplay();
  display.setTextSize(1);
  display.cp437(true);
  display.println(displayText);
  display.display();
}



void onReceive(int packetSize){
  
  String receivedText = " ";
  if (packetSize!=0) {
    // received a packet
  
    Serial.print("Received packet ");
    char flag = 0;
    char counter = 0;
    // read packet
    while (LoRa.available()) {
      
      receivedText += (char)LoRa.read();
      Serial.print((char)LoRa.read());
      flag = 1;
      // lcd.println((char)LoRa.read());
      counter++;
    }
    if(flag==1){
      Serial.println("Flushed!");
      drawText(receivedText);
      flag = 0;
      counter = 0;
      delete(&receivedText);
    }
    // print RSSI of packet
    Serial.print(" with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}

void setup() {
  LoRa.setPins(ss,reset,dio0);
  Serial.begin(115200);
  // lcd.init();
  // lcd.backlight();
  // lcd.println("Agrostation");
  // lcd.println("|Receiver|");
  while (!Serial);

  while(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed")); // Don't proceed, loop forever
  }

  Serial.println("LoRa Receiver");

  while(!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    LoRa.begin(433E6);
    delay(2000);
  }
  LoRa.onReceive(onReceive);
  LoRa.receive();
}

void loop() {
  // try to parse packet
 
}
