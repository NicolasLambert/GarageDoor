/*
 * AbstractTimeoutState.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "AbstractTimeoutState.h"

AbstractTimeoutState::AbstractTimeoutState(unsigned int const id) :
		AbstractDoorState(id) {
}

void AbstractTimeoutState::activate(unsigned long & notClosedDoorTimer, unsigned long & movingDoorTimer,
		bool& isForgottenOpenedDoor) {
	IOManager::getInstance()->m_red->off();
	IOManager::getInstance()->m_yellow->off();
	IOManager::getInstance()->m_green->off();
	IOManager::getInstance()->m_yellow->blink();

	IOManager::getInstance()->m_photoElecBeamPower->off();

	movingDoorTimer = 0UL;
}
