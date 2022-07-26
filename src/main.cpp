#include <Arduino.h>
#include <header.h>

IRrecv receiver(RECV_PIN);   // create a receiver object of the IRrecv class
decode_results results;      // create a results object of the decode_results class
unsigned int rgb_val[] = {0XFF, 0X00, 0X00}; // rgb_val[RED, BLUE, GREEN]
int current_timer;
bool dim = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
  receiver.enableIRIn(); // enable the receiver
  disableLEDFeedback(); // No annoying extra leds

  // RGB lighting
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
}

bool mode = false; // boolean trigger thingy
unsigned int timer_displacement = 0;
bool timer = false;

int setTimer(int timer_val) {
  if (mode) {
          if (timer) {
            timer_displacement = millis();
          }
          if (timer_displacement == 0) {
            timer_displacement = millis();
            timer = true;
          }
          
    return timer_val;
        }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (receiver.decode(&results)) {
    if (results.decode_type == IR_PROTOCOL) {
      switch (results.value) {
        case LIGHT_ON:
        mode = true;
        break;
      case LIGHT_OFF:
        mode = false;
        break;
      case RED_MODE:
        rgb_val[0] = 0XFF;
        rgb_val[1] = 0X00;
        rgb_val[2] = 0X00;
        break;
      case BLUE_MODE:
        rgb_val[0] = 0X00;
        rgb_val[1] = 0X00;
        rgb_val[2] = 0XFF;
        break;
      case GREEN_MODE:
        rgb_val[0] = 0X00;
        rgb_val[1] = 0XFF;
        rgb_val[2] = 0X00;
        break;
      case PURPLE_MODE:
        rgb_val[0] = 0XFF;
        rgb_val[1] = 0X00;
        rgb_val[2] = 0XFF;
        break;
      case YELLOW_MODE:
        rgb_val[0] = 0XFF;
        rgb_val[1] = 0XFF;
        rgb_val[2] = 0X00;
        break;
      case CYAN_MODE:
        rgb_val[0] = 0X00;
        rgb_val[1] = 0XFF;
        rgb_val[2] = 0XFF;
        break;
      case ORANGE_MODE:
        rgb_val[0] = 0XFF;
        rgb_val[1] = 0X64;
        rgb_val[2] = 0X00;
        break;
      case LIGHT_BLUE_MODE:
        rgb_val[0] = 0X00;
        rgb_val[1] = 0X8C;
        rgb_val[2] = 0XFF;
        break;
      case LIGHT_GREEN_MODE:
        rgb_val[0] = 0X00;
        rgb_val[1] = 0XFF;
        rgb_val[2] = 0XB4;
        break;
      case LIGHT_PURPLE_MODE:
        rgb_val[0] = 0XFF;
        rgb_val[1] = 0X10;
        rgb_val[2] = 0XFF;
        break;
      case FOUR_H_TIMER:
        current_timer = setTimer(4);
        break;
      case EIGHT_H_TIMER:
        current_timer = setTimer(8);
        break;
      case DELAYMODE:
        // So for some reason I can't pwm my way unto two signals at the same time
        // when using the IR, the program sort of deadlocks itself.
        break;
      }
    } else if (receiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
    }
    Serial.println(results.value, HEX);
    receiver.resume();
  }
  if (mode) {
      if (timer) {
        if (millis() - timer_displacement >= current_timer * 1000 * 60) {
            mode = false;
            timer = false;
            Serial.println("DED");
          }
      } else {
        analogWrite(R_PIN, rgb_val[0]);
        analogWrite(G_PIN, rgb_val[1]);
        analogWrite(B_PIN, rgb_val[2]);
      }
    } else {
      analogWrite(R_PIN, 0x00);
      analogWrite(G_PIN, 0x00);
      analogWrite(B_PIN, 0x00);
    }
}