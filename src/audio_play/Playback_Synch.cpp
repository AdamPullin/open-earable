#include "Playback_Synch.h"
#include "Flags.h"

Playback_Synch::Playback_Synch() {

}

Playback_Synch::~Playback_Synch() {

}

void Playback_Synch::setup(bool master) {
    MASTER = master;
    if (MASTER) {
        pin = EPIN_SDA;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    } else {
        pin = EPIN_SDA;
        pinMode(pin, INPUT);
        attachInterrupt(digitalPinToInterrupt(pin), handleInterrupt, RISING);
    };
}

void Playback_Synch::send_interrupt() {
    if (MASTER) {
        digitalWrite(pin, HIGH);
        delay(1000);
        digitalWrite(pin, LOW);
        Serial.println("Interrupt sent");
    }
}

void Playback_Synch::handleInterrupt() {
    PLAYING = true;
}

// Remove the global instance definition
Playback_Synch playback_synch;