/*
 * OpeningState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OPENINGSTATE_H_
#define OPENINGSTATE_H_

#include "../AbstractDoorState.h"

class OpeningState: public AbstractDoorState {
public:
	OpeningState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
	virtual char const * const getTweetMessage();
private:
	OpeningState();
};

#endif /* OPENINGSTATE_H_ */
