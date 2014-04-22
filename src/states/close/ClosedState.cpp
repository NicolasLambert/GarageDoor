/*
 * ClosedState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "ClosedState.h"

ClosedState::ClosedState(unsigned int const id) :
		AbstractDoorState(id) {
}

void ClosedState::activate(unsigned long & notClosedDoorTimer, unsigned long & movingDoorTimer,
		bool& isForgottenOpenedDoor) {
	IOManager::getInstance()->m_red->on();
	IOManager::getInstance()->m_yellow->off();
	IOManager::getInstance()->m_green->off();
	IOManager::getInstance()->m_photoElecBeamPower->off();

	notClosedDoorTimer = 0UL;
	movingDoorTimer = 0UL;
	isForgottenOpenedDoor = false;
}

char const * const ClosedState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_closedMsg;
}
