/*
 * ClosingState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "ClosingState.h"

ClosingState::ClosingState(unsigned int const id) :
		AbstractDoorState(id) {
}

void ClosingState::activate(unsigned long & notClosedDoorTimer, unsigned long & movingDoorTimer,
		bool& isForgottenOpenedDoor) {
	IOManager::getInstance()->m_red->off();
	IOManager::getInstance()->m_yellow->on();
	IOManager::getInstance()->m_green->off();
	IOManager::getInstance()->m_photoElecBeamPower->off();

	IOManager::getInstance()->m_red->blink();
	IOManager::getInstance()->m_yellow->blink();

	movingDoorTimer = millis();
}

const char* const ClosingState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_closingMsg;
}
