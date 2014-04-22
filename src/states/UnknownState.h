/*
 * UnknownState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef UNKNOWNSTATE_H_
#define UNKNOWNSTATE_H_

#include "AbstractDoorState.h"

class UnknownState: public AbstractDoorState {
public:
	UnknownState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
	virtual char const * const getTweetMessage();
private:
	UnknownState();
};

#endif /* UNKNOWNSTATE_H_ */
