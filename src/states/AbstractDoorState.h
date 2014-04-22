/*
 * AbstractDoorState.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef ABSTRACTDOORSTATE_H_
#define ABSTRACTDOORSTATE_H_

#include "../io/IOManager.h"
#include "AbstractDoorState.h"

class AbstractDoorState {
public:
	AbstractDoorState(unsigned int const id);
	virtual void activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer, bool &isForgottenOpenedDoor) = 0;
	virtual char const * const getTweetMessage();
	unsigned int const getId();
private:
	AbstractDoorState();
	unsigned int const m_id;
};

#endif /* ABSTRACTDOORSTATE_H_ */
