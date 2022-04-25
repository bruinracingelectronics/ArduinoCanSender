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
int i1 = 0;
int i2 = 54;
int i3 = 12;
int i4 = 80;
int i5 = 64;
int timer = 0;
void loop()
{
  tCAN message;

  message.id = 0x1; // formatted in HEX
  message.header.rtr = 0;
  message.header.length = 2; // formatted in DEC
  message.data[1] = i1;
  message.data[0] = i1 >> 8;

  i1 += 51;
  if (i1 > 12000)
  {
    i1 = 0;
  }
  mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
  mcp2515_send_message(&message);
  delay(10);
  if (timer % 20 == 0)
  {
    tCAN message2;

    message2.id = 0x2; // formatted in HEX
    message2.header.rtr = 0;
    message2.header.length = 2; // formatted in DEC
    message2.data[1] = i2;
    message2.data[0] = i2 >> 8;
    i2 = random(0, 6) + 54;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message2);
  }
  delay(10);

  if (timer % 20 == 0)
  {
    tCAN message3;

    message3.id = 0x3; // formatted in HEX
    message3.header.rtr = 0;
    message3.header.length = 2; // formatted in DEC
    message3.data[1] = i3;
    message3.data[0] = i3 >> 8;
    i3 = random(-1, 1) + 12;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message3);
  }
  delay(10);

  if (timer % 20 == 0)
  {
    tCAN message4;

    message4.id = 0x4; // formatted in HEX
    message4.header.rtr = 0;
    message4.header.length = 2; // formatted in DEC
    message4.data[1] = i4;
    message4.data[0] = i4 >> 8;
    i4 = random(0, 5) + 80;

    mcp2515_bit_modify(CANCTRL, (1 << REQOP2) | (1 << REQOP1) | (1 << REQOP0), 0);
    mcp2515_send_message(&message4);
  }
  delay(10);

  if (timer % 20 == 0)
  {
    tCAN message5;

    message5.id = 0x5; // formatted in HEX
    message5.header.rtr = 0;
    message5.header.length = 2; // formatted in DEC
    message5.data[1] = i5;
    message5.data[0] = i5 >> 8;

    i5 = random(-1, 1) + 64;
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