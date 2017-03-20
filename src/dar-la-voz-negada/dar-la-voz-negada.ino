
//libreria CMTU
#include <CapacitiveSensor.h>
CapacitiveSensor csense = CapacitiveSensor(4,3); //emisor, receptor

void setup() {
    csense.set_CS_AutocaL_Millis(0xFFFF); //inicializa el CMTU
    Serial.begin(57600); //UART para salida
    pinMode(13, OUTPUT); // salida de debug
    //pines como salida a nivel bajo, no conectados
    pinMode(2, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
}

void loop() {
    unsigned long capval = 0;
    
    digitalWrite(13, HIGH);
    capval = csense.capacitiveSensor(30);
    digitalWrite(13, LOW);
    Serial.println(capval);
    delay(50);
}

