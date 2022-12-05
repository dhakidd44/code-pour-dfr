/*
  Titre      : Projet ALLA avec un capteur de lumiere ambiante DFR0026
  Auteur     : Ernest Samuel Andre
  Date       : 05/12/2022
  Description: Obtenir une valeur a partir du capteeur et l'envoyer a notre tableau de bord
  Version    : 0.0.1
  credit du code :https://wiki.dfrobot.com/DFRobot_Ambient_Light_Sensor_SKU_DFR002
*/

#include <Arduino.h>
#include <SPI.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  
  wifiConnect();                  //Branchement au réseau WIFI
  MQTTConnect();                  //Branchement au broker MQTT

}
void loop()
{
      int val;
      val=analogRead(0);   //connect grayscale sensor to Analog 0
      Serial.println(val,DEC);//print the value to serial
      appendPayload("Lumiere",val);
      sendPayload();
      delay(1000);
}