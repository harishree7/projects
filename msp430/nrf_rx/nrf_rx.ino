    #include <Enrf24.h>
    #include <nRF24L01.h>
    #include <string.h>
    #include <SPI.h>
     
    Enrf24 radio(P2_0, P2_1, P2_2);  // P2.0=CE, P2.1=CSN, P2.2=IRQ
     
    const uint8_t rxaddr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x01 };
     
    const char *str_on = "ON";
    const char *str_off = "OFF";
     
    void setup() {
      SPI.begin();
      SPI.setDataMode(SPI_MODE0);
      SPI.setBitOrder(1); // MSB-first
      
      radio.begin();  // Defaults 1Mbps, channel 0, max TX power
      radio.setRXaddress((void*)rxaddr);
      
      pinMode(2, OUTPUT);
      digitalWrite(2, LOW);
      
      radio.enableRX();  // Start listening
    }
     
    void loop() {
      char inbuf[33];
      
      while (!radio.available(true))
         if (radio.read(inbuf)) {
        if (!strcmp(inbuf, str_on))
          digitalWrite(2, HIGH);
        if (!strcmp(inbuf, str_off))
          digitalWrite(2, LOW);
      }
    }
