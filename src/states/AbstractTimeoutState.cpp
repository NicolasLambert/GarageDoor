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
	IOManager::getInstance()->m_redLed->off();
	IOManager::getInstance()->m_yellowLed->off();
	IOManager::getInstance()->m_greenLed->off();
	IOManager::getInstance()->m_yellowLed->blink();

	IOManager::getInstance()->m_photoElecBeamPower->off();

	movingDoorTimer = 0UL;
}
