
//TRANSMITTER

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8, 9);
const byte address[6] = "00001";
int button_pin = 4;
boolean button_state = 0;

void setup()
{
  pinMode(button_pin, INPUT_PULLUP);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}


void loop()
{
  //INCREMENT BUTTON PIN
  button_state = digitalRead(button_pin);
  if (button_state == LOW)
  {
    const char text[] = "Your Button State is HIGH";
    radio.write(&text, sizeof(text));
  }
  else
  {
    const char text[] = "Your Button State is LOW";
    radio.write(&text, sizeof(text));
  }
  radio.write(&button_state, sizeof(button_state));
  delay(1000);

}
