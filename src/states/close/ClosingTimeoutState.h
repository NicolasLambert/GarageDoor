/*
 * ClosingTimeoutState.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef CLOSINGTIMEOUTSTATE_H_
#define CLOSINGTIMEOUTSTATE_H_

#include "../AbstractTimeoutState.h"

class ClosingTimeoutState: public AbstractTimeoutState {
public:
	ClosingTimeoutState(unsigned int const id);
	virtual char const * const getTweetMessage();
private:
	ClosingTimeoutState();
};

#endif /* CLOSINGTIMEOUTSTATE_H_ */
