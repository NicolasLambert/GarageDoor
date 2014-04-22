/*
 * OpenedState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OPENEDSTATE_H_
#define OPENEDSTATE_H_

#include "../AbstractDoorState.h"

class OpenedState: public AbstractDoorState {
public:
	OpenedState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
	virtual char const * const getTweetMessage();
private:
	OpenedState();
};

#endif /* OPENEDSTATE_H_ */
