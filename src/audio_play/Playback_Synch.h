#ifndef PLAYBACK_SYNCH_H
#define PLAYBACK_SYNCH_H

#include <Arduino.h>
#include "Earable_Pins.h"

class Playback_Synch {
public:
    Playback_Synch();
    ~Playback_Synch();

    void setup(bool role);

    void send_interrupt();
    static void handleInterrupt();

    int pin;
    bool MASTER;
};
extern Playback_Synch playback_synch;

#endif // PLAYBACK_SYNCH_H