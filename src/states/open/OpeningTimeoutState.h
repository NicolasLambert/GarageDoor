/*
 * OpeningTimeoutState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef OPENINGTIMEOUTSTATE_H_
#define OPENINGTIMEOUTSTATE_H_

#include "../AbstractTimeoutState.h"

class OpeningTimeoutState: public AbstractTimeoutState {
public:
	OpeningTimeoutState(unsigned int const id);
	virtual char const * const getTweetMessage();
private:
	OpeningTimeoutState();
};

#endif /* OPENINGTIMEOUTSTATE_H_ */
