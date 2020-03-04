/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
//    char* systemCode = argv[2];
    int code = atoi(argv[2]);
    int pin = atoi(argv[1]);

    if (wiringPiSetup () == -1) return 1;

    printf("sending systemCode[%i]\n", code);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(pin);
    mySwitch.setPulseLength(182);
//    mySwitch.sendTriState(systemCode);
    mySwitch.send(code, 24);
    return 0;
}
