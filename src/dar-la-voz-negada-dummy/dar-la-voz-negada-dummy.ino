#include <avr/pgmspace.h>

void setup() {
    Serial.begin(57600); //UART para salida
    pinMode(13, OUTPUT); // salida de debug
}

void loop() {
    unsigned long lbuffer = 0;
    static const PROGMEM unsigned long capval[] = {11, 10, 23, 10, 11, 249, 6138, 7413, 9790, 8174,
        229784, 95725, 32, 23, 24, 25, 39, 29, 23, 28, 29, 32, 32, 24, 26, 31, 541,
        3289, 5885, 3795, 6436, 4035, 6294, 3691, 981, 30, 20, 23, 18, 20, 21, 22, 2,
        12, 18, 16, 22, 0, 3, 13, 14, 28, 10, 11, 0, 0, 28, 17, 21, 4, 3, 18, 9, 26, 6,
        5, 5, 3, 29, 8, 17, 0, 0, 27, 12, 20, 3, 2, 1, 1, 0, 7, 5, 7, 4, 6, 7, 1, 4, 4,
        7, 7, 6, 4, 4, 5, 9, 4, 4, 6, 7, 8, 8, 13, 10, 11, 6, 10, 10, 8, 11, 6, 8, 7, 10,
        11, 11, 11, 3, 11, 11, 10, 11, 7, 11, 7, 9, 11, 9, 13, 7, 11, 8, 10, 13, 5, 12,
        8, 12, 8, 8, 13, 7, 13, 8, 11, 9, 4, 10, 7, 10, 7, 11, 12, 2, 10, 8, 10, 8, 6,
        8, 12, 10, 9, 11, 10, 5, 9, 9, 8, 8, 9, 8, 8, 8, 13, 9, 11, 3, 8, 13, 8, 10, 7,
        11, 7, 8, 12, 11, 13, 7, 10, 9, 8, 10, 1, 10, 7, 12, 11, 8, 10, 8, 11, 8, 11,
        10, 3, 10, 7, 13, 9, 9, 8, 6, 13, 11, 11, 9, 5, 11, 9, 8, 9, 7, 8, 7, 8, 13, 9,
        11, 0, 9, 11, 8, 11, 5, 11, 3, 9, 8, 10, 13, 5, 11, 10, 8, 10, 7, 11, 3, 12, 11,
        8, 10, 1, 13, 8, 11, 9, 9, 10, 8, 10, 10, 10, 8, 1, 10, 10, 11, 11, 9, 8, 7, 7,
        10, 11, 11, 3, 12, 10, 11, 11, 8, 8, 8, 12, 11, 11, 11, 4, 9, 12, 8, 9, 8, 7,
        12, 9, 11, 6, 8, 8, 13, 11, 11, 11, 3, 8, 8, 8, 11, 9, 11, 4, 10, 8, 8, 13, 7,
        10, 10, 11, 7, 8, 11, 5, 10, 10, 10, 9, 0, 13, 9, 11, 10, 10, 8, 5, 11, 8, 11,
        9, 2, 8, 9, 8, 9, 13, 8, 7, 10, 10, 8, 9, 5, 10, 10, 8, 13, 10, 8, 10, 10, 12,
        8, 10, 4, 9, 11, 8, 13, 4, 10, 6, 11, 13, 11, 10, 2, 10, 8, 10, 11, 4, 11, 6,
        11, 13, 11, 11, 5, 11, 9, 8, 8, 10, 12, 7, 13, 8, 8, 13, 12, 11, 8, 11, 9, 11,
        13, 9, 11, 9, 14, 11, 21, 11, 9, 13, 12, 39, 20, 31, 11, 13, 39, 34, 39, 17, 26,
        38, 33, 40, 28, 28, 34, 33, 40, 39, 38, 31, 45, 38, 39, 41, 34, 43, 41, 38, 40,
        52, 43, 40, 42, 41, 55, 46, 49, 54, 39, 50, 38, 60, 59, 39, 43, 41, 47, 51, 40,
        42, 40, 50, 49, 43, 52, 42, 48, 42, 57, 62, 41, 51, 37, 55, 58, 42, 47, 41, 61,
        60, 42, 56, 43, 56, 51, 52, 54, 39, 59, 43, 66, 69, 42, 54, 40, 67, 65, 45, 60,
        40, 64, 67, 49, 62, 40, 63, 53, 57, 62, 42, 57, 43, 73, 67, 41, 62, 41, 69, 65,
        46, 55, 39, 64, 62, 45, 58, 44, 67, 56, 57, 63, 38, 64, 50, 69, 67, 59, 69, 42,
        67, 71, 60, 63, 48, 70, 72, 58, 71, 41, 66, 67, 72, 69, 64, 71, 70, 72, 68, 71,
        71, 40, 19, 27, 38, 39, 41, 64, 66, 60, 71, 54, 71, 71, 69, 68, 69, 70, 72, 68,
        68, 71, 68, 63, 67, 71, 69, 68, 69, 72, 69, 72, 68, 72, 69, 72, 69, 72, 67, 69,
        69, 70, 71, 75, 69, 73, 68, 69, 80, 71, 73, 69, 71, 82, 71, 76, 69, 73, 78, 69,
        76, 70, 69, 77, 69, 82, 74, 69, 73, 69, 94, 69, 69, 73, 73, 90, 70, 70, 73, 74,
        85, 69, 75, 76, 73, 81, 70, 78, 69, 69, 83, 77, 74, 69, 71, 82, 77, 77, 71, 71,
        74, 77, 87, 75, 69, 69, 72, 82, 76, 69, 70, 71, 77, 71, 73, 70, 75, 77, 69, 70,
        70, 72, 72, 69, 80, 67, 68, 70, 78, 74, 69, 69, 70, 72, 74, 69, 71, 66, 70, 59,
        67, 67, 71, 68, 41, 43, 41, 17, 9, 41, 17, 36, 11, 17, 37, 38, 41, 70, 71, 69,
        69, 68, 73, 71, 69, 69, 82, 72, 77, 69, 72, 83, 76, 88, 71, 73, 69, 71, 42, 67,
        68, 72, 71, 71, 69, 72, 75, 73, 87, 71, 80, 77, 71, 92, 74, 82, 74, 70, 94, 80,
        90, 69, 69, 98, 79, 91, 69, 71, 97, 80, 92, 73, 77, 92, 78, 85, 73, 77, 90, 78,
        90, 72, 75, 82, 73, 95, 77, 72, 73, 70, 95, 77, 77, 74, 72, 90, 75, 78, 70, 72,
        95, 72, 87, 72, 69, 92, 77, 89, 71, 73, 93, 77, 94, 78, 86, 95, 85, 101, 97, 91,
        93, 88, 98, 96, 85, 93, 95, 100, 91, 82, 91, 97, 100, 88, 96, 92, 96, 99, 85,
        96, 92, 87, 101, 93, 100, 87, 92, 97, 98, 95, 84, 79, 100, 98, 99, 86, 85, 99,
        97, 98, 88, 96, 98, 101, 98, 90, 102, 100, 98, 98, 96, 101, 100, 96, 98, 101,
        103, 97, 101, 100, 103, 96, 99, 96, 97, 100, 94, 98, 96, 98, 102, 96, 100, 102,
        98, 94, 93, 102, 99, 101, 94, 95, 96, 98, 98, 93, 99, 99, 99, 100, 101, 97, 97,
        102, 97, 101, 98, 103, 96, 98, 98, 99, 91, 96, 99, 100, 100, 96, 104, 100, 99,
        100, 94, 100, 101, 97, 96, 95, 107, 98, 101, 96, 99, 101, 97, 97, 103, 105, 111,
        100, 98, 98, 113, 103, 101, 100, 101, 111, 104, 97, 99, 100, 97, 102, 97, 103,
        97, 95, 108, 100, 100, 97, 89, 102, 100, 98, 98, 87, 107, 101, 98, 103, 107,
        105, 98, 99, 101, 110, 104, 100, 100, 101, 108, 101, 101, 102, 100, 104, 96,
        103, 98, 100, 105, 104, 99, 99, 100, 103, 108, 98, 98, 100, 94, 109, 103, 100,
        97, 105, 107, 97, 98, 97, 118, 105, 100, 98, 98, 108, 101, 100, 103, 101, 108,
        111, 98, 100, 100, 110, 114, 101, 103, 103, 117, 118, 98, 102, 100, 120, 126,
        97, 104, 105, 123, 117, 98, 106, 105, 119, 114, 98, 102, 101, 104, 87, 98, 86,
        80, 71, 68, 69, 67, 69, 70, 69, 71, 96, 98, 92, 111, 100, 97, 98, 122, 125, 101,
        106, 103, 126, 118, 97, 97, 98, 121, 107, 99, 105, 100, 112, 96, 100, 104, 98,
        112, 111, 101, 69, 69, 68, 70, 69, 69, 87, 72, 81, 99, 98, 100, 98, 102, 97,
        101, 98, 112, 108, 99, 99, 98, 109, 105, 100, 105, 100, 111, 105, 101, 107, 100,
        117, 118, 101, 106, 99, 112, 117, 98, 102, 98, 122, 121, 100, 101, 101, 126,
        122, 100, 97, 98, 126, 119, 101, 103, 98, 123, 116, 98, 113, 100, 123, 114, 100,
        119, 101, 123, 130, 100, 113, 101, 127, 125, 99, 112, 101, 127, 128, 99, 115,
        101, 123, 126, 98, 114, 102, 123, 128, 100, 114, 107, 115, 115, 98, 115, 107,
        115, 118, 98, 126, 106, 113, 119, 100, 122, 115, 109, 121, 99, 120, 111, 113,
        124, 102, 119, 109, 113, 116, 99, 117, 116, 109, 119, 101, 120, 123, 103, 116,
        98, 125, 117, 105, 110, 100, 121, 121, 103, 111, 101, 125, 119, 100, 106, 101,
        124, 126, 98, 116, 101, 125, 118, 98, 114, 100, 125, 124, 100, 117, 98, 126,
        129, 101, 115, 97, 127, 127, 97, 117, 98, 131, 127, 101, 109, 100, 125, 121, 98,
        109, 98, 123, 122, 99, 117, 102, 121, 125, 98, 113, 105, 116, 119, 98, 119, 109,
        111, 113, 98, 117, 107, 109, 119, 100, 117, 109, 113, 120, 101, 125, 119, 111,
        120, 100, 120, 122, 108, 115, 100, 121, 122, 102, 117, 98, 119, 120, 100, 113,
        100, 120, 118, 101, 112, 99, 122, 114, 97, 105, 98, 124, 116, 103, 113, 101,
        122, 120, 97, 116, 98, 122, 124, 97, 118, 101, 126, 128, 99, 119, 97, 124, 126,
        100, 111, 98, 127, 123, 98, 105, 100, 121, 121, 99, 107, 108, 119, 122, 100,
        108, 104, 108, 115, 98, 118, 112, 103, 108, 101, 117, 113, 100, 117, 100, 121,
        112, 104, 125, 99, 124, 120, 103, 121, 99, 123, 125, 107, 117, 99, 118, 125,
        103, 113, 99, 125, 125, 101, 108, 101, 126, 123, 100, 105, 102, 129, 126, 98,
        115, 101, 126, 125, 98, 113, 104, 125, 123, 103, 114, 101, 119, 122, 98, 119, 9,
        100, 96, 100, 73, 68, 70, 44, 65, 71, 76, 69, 78, 79, 77, 102, 83, 90, 80, 83,
        97, 97, 97, 86, 87, 101, 87, 90, 69, 67, 40, 0, 0, 0, 0, 2, 2, 0, 2, 4, 2, 3, 6,
        9};
        
    for (int i = 0; i < 1500; i++) {
        lbuffer = pgm_read_word_near(capval + i);
        digitalWrite(13, HIGH);
        Serial.println(lbuffer);
        digitalWrite(13, LOW);
        delay(50);
    }
}
