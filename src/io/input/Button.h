/*
 * Button.h
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "DigitalInput.h"

#define DEFAULT_DEBOUNCE_DELAY 50

class Button: public DigitalInput {
public:
	Button(int const pin, unsigned int debounceDelay = DEFAULT_DEBOUNCE_DELAY);
};

#endif /* BUTTON_H_ */
