/*
 * ClosingTimeoutState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "ClosingTimeoutState.h"

ClosingTimeoutState::ClosingTimeoutState(unsigned int const id) :
		AbstractTimeoutState(id) {
}

const char* const ClosingTimeoutState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_closingTimeOutMsg;
}
