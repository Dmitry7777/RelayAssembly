#include "RelayAssembly.h"
#include <stdarg.h> // For variable argument list processing

// Dynamic constructor that accepts variable number of relay pins
RelayAssembly::RelayAssembly(int numRelays, ...) {
    // Allocate memory for storing relay pins
    _relayPins = new int[numRelays];
    _numRelays = numRelays;

    va_list args;
    va_start(args, numRelays);

    // Store relay pins from the variable argument list
    for (int i = 0; i < numRelays; ++i) {
        _relayPins[i] = va_arg(args, int);
    }

    va_end(args);

    // Initialize all relay pins as outputs
    for (int i = 0; i < numRelays; ++i) {
        pinMode(_relayPins[i], OUTPUT);
        digitalWrite(_relayPins[i], LOW); // Initially keep all relays OFF
    }
}

// Turn ON a specified relay
void RelayAssembly::turnOn(int relayNumber) {
    if (relayNumber >= 1 && relayNumber <= _numRelays) {
        digitalWrite(_relayPins[relayNumber - 1], HIGH);
    } else {
        Serial.println("Invalid relay number.");
    }
}

// Turn OFF a specified relay
void RelayAssembly::turnOff(int relayNumber) {
    if (relayNumber >= 1 && relayNumber <= _numRelays) {
        digitalWrite(_relayPins[relayNumber - 1], LOW);
    } else {
        Serial.println("Invalid relay number.");
    }
}

// Toggle a specified relay
void RelayAssembly::toggle(int relayNumber) {
    if (relayNumber >= 1 && relayNumber <= _numRelays) {
        int currentState = digitalRead(_relayPins[relayNumber - 1]);
        digitalWrite(_relayPins[relayNumber - 1], !currentState);
    } else {
        Serial.println("Invalid relay number.");
    }
}

// Turn ON all relays
void RelayAssembly::turnAllOn() {
    for (int i = 0; i < _numRelays; ++i) {
        digitalWrite(_relayPins[i], HIGH);
    }
}

// Turn OFF all relays
void RelayAssembly::turnAllOff() {
    for (int i = 0; i < _numRelays; ++i) {
        digitalWrite(_relayPins[i], LOW);
    }
}