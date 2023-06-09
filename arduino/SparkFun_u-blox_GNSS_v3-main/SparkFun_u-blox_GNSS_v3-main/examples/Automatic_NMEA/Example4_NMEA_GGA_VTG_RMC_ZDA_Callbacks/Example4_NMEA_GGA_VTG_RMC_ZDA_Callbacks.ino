/*
  Get the latest GGA, VTG, RMC, ZDA NMEA sentence using callbacks
  By: Paul Clark
  SparkFun Electronics
  Date: March 2nd, 2022
  License: MIT. See license file for more information

  ** Please note: this example will not run on Arduino Uno. See https://github.com/sparkfun/SparkFun_u-blox_GNSS_Arduino_Library/blob/main/README.md#memory-usage

  This example shows how to turn on/off the NMEA sentences being output over I2C.
  It then demonstrates how to get the latest GGA, VTG, RMC or ZDA message autonomously using callbacks.

  If the module is using multiple GNSS constellations, the GGA message will be prefixed with Talker ID "GN" instead of "GP".
  This example shows how to change the Talker ID so the GNGGA messages become GPGGA.
  It also shows how to enable "high precision mode" to include extra decimal places in the GGA messages.

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  SparkFun GPS-RTK2 - ZED-F9P (GPS-15136)    https://www.sparkfun.com/products/15136
  SparkFun GPS-RTK-SMA - ZED-F9P (GPS-16481) https://www.sparkfun.com/products/16481
  SparkFun MAX-M10S Breakout (GPS-18037)     https://www.sparkfun.com/products/18037
  SparkFun ZED-F9K Breakout (GPS-18719)      https://www.sparkfun.com/products/18719
  SparkFun ZED-F9R Breakout (GPS-16344)      https://www.sparkfun.com/products/16344

  Hardware Connections:
  Plug a Qwiic cable into the GNSS and a RedBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
*/

#include <Wire.h> //Needed for I2C to GNSS

#include <SparkFun_u-blox_GNSS_v3.h> //Click here to get the library: http://librarymanager/All#SparkFun_u-blox_GNSS_v3
SFE_UBLOX_GNSS myGNSS;

// Callback: printGPGGA will be called when new GPGGA NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_GGA_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGPGGAcallback
//        /               _____  This _must_ be NMEA_GGA_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGPGGA(NMEA_GGA_data_t *nmeaData)
{
    Serial.print(F("\r\nGPGGA: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGNGGA will be called if new GNGGA NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_GGA_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGNGGAcallback
//        /               _____  This _must_ be NMEA_GGA_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGNGGA(NMEA_GGA_data_t *nmeaData)
{
    Serial.print(F("\r\nGNGGA: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGPVTG will be called when new GPVTG NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_VTG_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGPVTGcallback
//        /               _____  This _must_ be NMEA_VTG_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGPVTG(NMEA_VTG_data_t *nmeaData)
{
    Serial.print(F("\r\nGPVTG: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGNVTG will be called if new GNVTG NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_VTG_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGNVTGcallback
//        /               _____  This _must_ be NMEA_VTG_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGNVTG(NMEA_VTG_data_t *nmeaData)
{
    Serial.print(F("\r\nGNVTG: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGPRMC will be called when new GPRMC NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_RMC_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGPRMCcallback
//        /               _____  This _must_ be NMEA_RMC_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGPRMC(NMEA_RMC_data_t *nmeaData)
{
    Serial.print(F("\r\nGPRMC: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGNRMC will be called if new GNRMC NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_RMC_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGNRMCcallback
//        /               _____  This _must_ be NMEA_RMC_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGNRMC(NMEA_RMC_data_t *nmeaData)
{
    Serial.print(F("\r\nGNRMC: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGPZDA will be called when new GPZDA NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_ZDA_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGPZDAcallback
//        /               _____  This _must_ be NMEA_ZDA_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGPZDA(NMEA_ZDA_data_t *nmeaData)
{
    Serial.print(F("\r\nGPZDA: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

// Callback: printGNZDA will be called if new GNZDA NMEA data arrives
// See u-blox_structs.h for the full definition of NMEA_ZDA_data_t
//         _____  You can use any name you like for the callback. Use the same name when you call setNMEAGNZDAcallback
//        /               _____  This _must_ be NMEA_ZDA_data_t
//        |              /           _____ You can use any name you like for the struct
//        |              |          /
//        |              |          |
void printGNZDA(NMEA_ZDA_data_t *nmeaData)
{
    Serial.print(F("\r\nGNZDA: Length: "));
    Serial.print(nmeaData->length);
    Serial.print(F("\tData: "));
    Serial.print((const char *)nmeaData->nmea); // .nmea is printable (NULL-terminated) and already has \r\n on the end
}

void setup()
{

  Serial.begin(115200);
  Serial.println(F("SparkFun u-blox GNSS Example"));

  Wire.begin();

  //myGNSS.enableDebugging(); // Uncomment this line to enable debug messages on Serial

  if (myGNSS.begin() == false)
  {
    Serial.println(F("u-blox GNSS not detected at default I2C address. Please check wiring. Freezing."));
    while (1)
      ;
  }

  // Disable or enable various NMEA sentences over the I2C interface
  myGNSS.setI2COutput(COM_TYPE_NMEA | COM_TYPE_UBX); // Turn on both UBX and NMEA sentences on I2C. (Turn off RTCM and SPARTN)
  myGNSS.newCfgValset(VAL_LAYER_RAM_BBR); // Use cfgValset to disable / enable individual NMEA messages
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_GLL_I2C, 0);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_GSA_I2C, 0);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_GSV_I2C, 0);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_RMC_I2C, 1);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_VTG_I2C, 1);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_GGA_I2C, 1);
  myGNSS.addCfgValset(UBLOX_CFG_MSGOUT_NMEA_ID_ZDA_I2C, 1);
  if (myGNSS.sendCfgValset()) // Send the configuration VALSET
    Serial.println(F("NMEA messages were configured successfully"));
  else
    Serial.println(F("NMEA message configuration failed!"));

  // Set the Main Talker ID to "GP". The NMEA GGA messages will be GPGGA instead of GNGGA
  myGNSS.setMainTalkerID(SFE_UBLOX_MAIN_TALKER_ID_GP);
  //myGNSS.setMainTalkerID(SFE_UBLOX_MAIN_TALKER_ID_DEFAULT); // Uncomment this line to restore the default main talker ID

  myGNSS.setHighPrecisionMode(true); // Enable High Precision Mode - include extra decimal places in the GGA messages

  //myGNSS.saveConfiguration(VAL_CFG_SUBSEC_IOPORT | VAL_CFG_SUBSEC_MSGCONF); //Optional: Save only the ioPort and message settings to NVM

  Serial.println(F("Messages configured"));

  //myGNSS.setNMEAOutputPort(Serial); // Uncomment this line to echo all NMEA data to Serial for debugging

  // Set up the callback for GPGGA
  myGNSS.setNMEAGPGGAcallbackPtr(&printGPGGA);

  // Set up the callback for GNGGA
  myGNSS.setNMEAGNGGAcallbackPtr(&printGNGGA);

  // Set up the callback for GPVTG
  myGNSS.setNMEAGPVTGcallbackPtr(&printGPVTG);

  // Set up the callback for GNVTG
  myGNSS.setNMEAGNVTGcallbackPtr(&printGNVTG);

  // Set up the callback for GPRMC
  myGNSS.setNMEAGPRMCcallbackPtr(&printGPRMC);

  // Set up the callback for GNRMC
  myGNSS.setNMEAGNRMCcallbackPtr(&printGNRMC);

  // Set up the callback for GPZDA
  myGNSS.setNMEAGPZDAcallbackPtr(&printGPZDA);

  // Set up the callback for GNZDA
  myGNSS.setNMEAGNZDAcallbackPtr(&printGNZDA);
}

void loop()
{
  myGNSS.checkUblox(); // Check for the arrival of new data and process it.
  myGNSS.checkCallbacks(); // Check if any callbacks are waiting to be processed.

  Serial.print(".");
  delay(50);
}
