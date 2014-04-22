/*
 * ClosedState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef CLOSEDSTATE_H_
#define CLOSEDSTATE_H_

#include "../AbstractDoorState.h"

class ClosedState: public AbstractDoorState {
public:
	ClosedState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
	virtual char const * const getTweetMessage();
private:
	ClosedState();
};

#endif /* CLOSEDSTATE_H_ */
