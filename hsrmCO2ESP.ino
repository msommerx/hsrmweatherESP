#include <SoftwareSerial.h>

byte com[]={0xff,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};  //Befehl zum Auslesen der CO2 Konzentration
byte return1[9];                                            //hier kommt der zurückgegeben Wert des ersten Sensors rein
int concentration1;                                         //CO2-Konzentration des ersten Sensors
int minimum1;                                               //Minimum-Wert des ersten Sensors
int temp1;                                                  //Temperatur-Wert des ersten Sensors
byte status1;                                               //Status des ersten Sensors
byte bit0;
byte bit1;
byte bit2;
byte bit3;
byte bit4;
byte bit5;
byte bit6;
byte bit7;
byte bit8;

 
void setup() {
  Serial.begin(9600);   //Initialisierung Serielle Schnittstelle zum Computer
}
 
void loop() {
   while (Serial.available() >0) {     //Hier wird der Buffer der Seriellen Schnittstelle gelehrt 
    Serial.read();
   }

   Serial.write(com,9);                           //Befehl zum Auslesen der CO2 Konzentration
   Serial.readBytes(return1,9);                   //Auslesen der Antwort
   concentration1 = return1[2]*256+return1[3];    //Berechnung der Konzentration
   temp1 = return1[4]-40;                         //Berechnung der Temperatur
   minimum1 = return1[6]*256+return1[7];          //Berechnung des Minimums
   status1 = return1[5];                          //Berechnung des Status
   bit0 = return1[0];
   bit1 = return1[1];
   bit2 = return1[2];
   bit3 = return1[3];
   bit4 = return1[4];
   bit5 = return1[5];
   bit6 = return1[6];
   bit7 = return1[7];
   bit8 = return1[8];
   
   Serial.print("0: ");
   Serial.print(bit0, HEX);
//   Serial.print(bit0);
   Serial.print("  1: ");
   Serial.print(bit1, HEX);
//   Serial.print(bit1);
   Serial.print("  2: ");
   Serial.print(bit2, HEX);
//   Serial.print(bit2);
   Serial.print("  3: ");
   Serial.print(bit3, HEX);
//   Serial.print(bit3);
   Serial.print("  4: ");
   Serial.print(bit4, HEX);
//   Serial.print(bit4);
   Serial.print("  5: ");
   Serial.print(bit5, HEX);
//   Serial.print(bit5);
   Serial.print("  6: ");
   Serial.print(bit6, HEX);
//   Serial.print(bit6);
   Serial.print("  7: ");
   Serial.print(bit7, HEX);
//   Serial.print(bit7);
   Serial.print(" 8: ");
   Serial.print(bit8, HEX);
//   Serial.print(bit8);
   Serial.println();

//        
//   Serial.print("Zeit = ");                       //Senden der Werte an den PC 
//   Serial.print(millis());                        //Am Angfang wird die Zeit in ms gesendet, die der Arduino in Betrieb ist
   Serial.print(" ; Sensor 1: CO2 = ");
   Serial.print(concentration1);
   Serial.print(" ; Temp = ");
   Serial.print(temp1);
   Serial.print(" ; Minimum = ");
   Serial.print(minimum1);
   Serial.print(" ; Status = ");
   Serial.print(status1);
   Serial.println();
//
//   
   delay(1000);                              //10s warten
}
