#include <IRremote.h> // include the IRremote library

#define RECV_PIN 5 // define the IR receiver pin

// RGB pins
#define R_PIN 11
#define G_PIN 10
#define B_PIN 9

// Change these to your own controller
// The constants bellow are from an i-Zoom controller from some lights i got from a dollar store
#define IR_PROTOCOL         NEC
#define LIGHT_OFF           0X1FE58A7
#define LIGHT_ON            0X1FE48B7
#define RED_MODE            0X1FE20DF
#define GREEN_MODE          0X1FEA05F
#define BLUE_MODE           0X1FE609F
#define CYAN_MODE           0X1FED827
#define ORANGE_MODE         0X1FEE01F
#define PURPLE_MODE         0X1FEF807
#define YELLOW_MODE         0X1FE30CF

#define LIGHT_GREEN_MODE    0X1FE10EF
#define LIGHT_BLUE_MODE     0X1FE906F
#define LIGHT_PURPLE_MODE   0X1FE708F

#define MULTICOLOR_MODE     0X1FEC03F
#define DELAYMODE           0X1FE7887
#define FOUR_H_TIMER        0X1FE807F
#define EIGHT_H_TIMER       0X1FE40BF