/*
 * OpeningState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OpeningState.h"

OpeningState::OpeningState(unsigned int const id) :
		AbstractDoorState(id) {
}

void OpeningState::activate(unsigned long & notClosedDoorTimer, unsigned long & movingDoorTimer,
		bool& isForgottenOpenedDoor) {
	IOManager::getInstance()->m_redLed->off();
	IOManager::getInstance()->m_yellowLed->on();
	IOManager::getInstance()->m_greenLed->off();
	IOManager::getInstance()->m_photoElecBeamPower->off();

	IOManager::getInstance()->m_yellowLed->blink();
	IOManager::getInstance()->m_greenLed->blink();

	unsigned long currentTime = millis();
	notClosedDoorTimer = currentTime;
	movingDoorTimer = currentTime;
}

const char* const OpeningState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_openingMsg;
}
