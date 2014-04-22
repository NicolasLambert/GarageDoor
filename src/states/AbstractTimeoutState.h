/*
 * AbstractTimeoutState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTTIMEOUTSTATE_H_
#define ABSTRACTTIMEOUTSTATE_H_

#include "AbstractDoorState.h"

class AbstractTimeoutState: public AbstractDoorState {
public:
	AbstractTimeoutState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor);
private:
	AbstractTimeoutState();
};

#endif /* ABSTRACTTIMEOUTSTATE_H_ */
