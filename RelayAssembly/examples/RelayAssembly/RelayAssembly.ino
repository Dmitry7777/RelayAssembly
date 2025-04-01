#include <Arduino.h>
#include "RelayAssembly.h"

// Define relay pins
#define RELAY1_PIN 2
#define RELAY2_PIN 3
#define RELAY3_PIN 4

// Create a RelayAssembly object with 3 relays
RelayAssembly relays(3, RELAY1_PIN, RELAY2_PIN, RELAY3_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Toggle relays every 1 second
    relays.toggle(1);
    delay(1000);
    relays.toggle(2);
    delay(1000);
    relays.toggle(3);
    delay(1000);
}