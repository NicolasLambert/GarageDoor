/*
 * AbstractDoorState.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "AbstractDoorState.h"

AbstractDoorState::AbstractDoorState(const unsigned int id) :
		m_id(id) {
}

const unsigned int AbstractDoorState::getId() {
	return m_id;
}

const char* const AbstractDoorState::getTweetMessage() {
	// Default is no tweet Message
	return 0;
}
