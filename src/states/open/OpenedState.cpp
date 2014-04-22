/*
 * OpenedState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "OpenedState.h"

OpenedState::OpenedState(unsigned int const id) :
		AbstractDoorState(id) {
}

void OpenedState::activate(unsigned long & notClosedDoorTimer, unsigned long & movingDoorTimer,
		bool& isForgottenOpenedDoor) {
	IOManager::getInstance()->m_red->off();
	IOManager::getInstance()->m_yellow->off();
	IOManager::getInstance()->m_green->on();
	IOManager::getInstance()->m_photoElecBeamPower->on();

	movingDoorTimer = 0UL;
}

const char* const OpenedState::getTweetMessage() {
	return IOManager::getInstance()->m_sentencesFile->m_openedMsg;
}
