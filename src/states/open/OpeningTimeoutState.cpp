/*
 * OpeningTimeoutState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OpeningTimeoutState.h"

OpeningTimeoutState::OpeningTimeoutState(unsigned int const id) :
		AbstractTimeoutState(id) {
}

const char* const OpeningTimeoutState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_openingTimeOutMsg;
}
