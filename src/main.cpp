/****************************************************************************
CAN Write Demo for the SparkFun CAN Bus Shield.

Written by Stephen McCoy.
Original tutorial available here: http://www.instructables.com/id/CAN-Bus-Sniffing-and-Broadcasting-with-Arduino
Used with permission 2016. License CC By SA.

Distributed as-is; no warranty is given.
*************************************************************************/

#include <Arduino.h>
#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

#include "utils.h"

using namespace Utils;

int i1 = 0;
float f2 = 190;
float f3 = 12.59;
float f4 = 13.8;
float f5 = 64.55;

//********************************Setup Loop*********************************//

void setup()
{
  Serial.begin(9600);
  Serial.println("CAN Write - Testing transmission of CAN Bus messages");
  delay(1000);

  if (Canbus.init(CANSPEED_125)) // Initialise MCP2515 CAN controller at the specified speed
    Serial.println("CAN Init ok");
  else
    Serial.println("Can't init CAN");

  delay(1000);
}

//********************************Main Loop*********************************//


int timer = 0;
void loop()
{
  tCAN message;

  message = makeInt16Message(0x1, i1);

  ////// FRAME 1 - RPM
  i1 += 51;
  if (i1 > 12000)
  {
    i1 = 0;
  }
  mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
  mcp2515_send_message(&message);
  delay(10);


  //// FRAME 2 - COOLANT
  if (timer % 20 == 0)
  {
    tCAN message2;

    message2 = makeFloatMessage(0x2, f2);

    f2 = random(-100, 100) / 50.0 + 190.0;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message2);
  }
  delay(10);

  ////// FRAME 3 - VOLTAGE
  if (timer % 20 == 0)
  {
    tCAN message3;

    message3 = makeFloatMessage(0x3, f3);

    f3 = random(-5, 5) / 10.0 + 12.5;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message3);
  }
  delay(10);

  ///// FRAME 4 - AFR
  if (timer % 20 == 0)
  {
    tCAN message4;

    message4 = makeFloatMessage(0x4,f4);

    f4 = random(0, 10) / 100.0 + 13.8;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message4);
  }
  delay(10);

  //// FRAME 5 - BIAS DATA
  if (timer % 20 == 0)
  {
    tCAN message5;

    message5 = makeFloatMessage(5, f5);

    f5 = random(0, 4) / 6.0 + 64.0;
    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message5);
  }
  delay(10);
  timer++;
  if (timer > 9000)
  {
    timer = 0;
  }
}