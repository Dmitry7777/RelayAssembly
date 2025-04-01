#ifndef RELAY_ASSEMBLY_H
#define RELAY_ASSEMBLY_H

#include <Arduino.h>

class RelayAssembly {
public:
    // Dynamic constructor taking variable arguments for relay pins
    RelayAssembly(int numRelays, ...);

    // Methods to control individual relays
    void turnOn(int relayNumber);
    void turnOff(int relayNumber);
    void toggle(int relayNumber);

    // Method to turn on/off all relays
    void turnAllOn();
    void turnAllOff();

private:
    // Array to store relay pins
    int *_relayPins;
    int _numRelays;
};

#endif // RELAY_ASSEMBLY_H