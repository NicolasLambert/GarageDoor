/*
 * ClosingState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef CLOSINGSTATE_H_
#define CLOSINGSTATE_H_

#include "../AbstractDoorState.h"

class ClosingState: public AbstractDoorState {
public:
	ClosingState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
	virtual char const * const getTweetMessage();
private:
	ClosingState();
};

#endif /* CLOSINGSTATE_H_ */
