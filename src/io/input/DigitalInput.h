/*
 * DigitalInput.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

#include "../DigitalIO.h"

class DigitalInput: public DigitalIO {
public:
	typedef void (*InputChangeListener)(bool const oldState, bool const newState);
	DigitalInput(int const pin, bool const reversed, unsigned int debounceDelay);
	void setListener(InputChangeListener listener);
	virtual bool const getState();
	virtual void update(unsigned long currentTime);
private:
	unsigned long m_lastChangeTime;
	bool m_lastState;
	bool m_currentState;
	InputChangeListener m_listener;
	unsigned int m_debounceDelay;
};

#endif /* DIGITALINPUT_H_ */
