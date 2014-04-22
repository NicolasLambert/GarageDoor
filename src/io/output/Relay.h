/*
 * Relay.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef RELAY_H_
#define RELAY_H_

#include "DigitalOutput.h"
#define DEFAULT_TOGGLE_DURATION 400

class Relay: public DigitalOutput {
public:
	Relay(int const pin);
	void toggleFor(unsigned int delay = DEFAULT_TOGGLE_DURATION);
	virtual void on();
	virtual void off();
	virtual void update(unsigned long currentTime);
private:
	unsigned long m_maintainUntil; // will store until when relay should be maintained
};

#endif /* RELAY_H_ */
