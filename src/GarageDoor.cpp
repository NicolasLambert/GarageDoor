// Do not remove the include below
#include "GarageDoor.h"

// Uncomment to turn ON serial debugging
//#define PRINT_DEBUG_MSGS 1

// Setup function
void setup() {
#ifdef PRINT_DEBUG_MSGS
	Serial.begin(9600);
	Serial.println("Start...");
#endif
}

// Main loop
void loop() {
	DoorStateManager::getInstance()->update(millis());
	WebManager::getInstance()->update();
}
