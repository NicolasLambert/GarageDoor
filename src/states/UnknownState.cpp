/*
 * UnknownState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "UnknownState.h"

UnknownState::UnknownState(unsigned int const id) :
		AbstractDoorState(id) {
}

void UnknownState::activate(unsigned long &notClosedDoorTimer, unsigned long &movingDoorTimer,
		bool &isForgottenOpenedDoor) {
	IOManager::getInstance()->m_redLed->off();
	IOManager::getInstance()->m_yellowLed->blink();
	IOManager::getInstance()->m_greenLed->off();
	IOManager::getInstance()->m_photoElecBeamPower->off();
}

const char* const UnknownState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_unknownMsg;
}
