/*
 * DoorStateManager.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "DoorStateManager.h"

//#define PRINT_DEBUG_MSGS

DoorStateManager::DoorStateManager() :

		// States
		m_unknownState(new UnknownState(0)),
		m_openingState(new OpeningState(1)),
		m_openingTimeoutState(new OpeningTimeoutState(2)),
		m_openedState(new OpenedState(3)),
		m_closingState(new ClosingState(4)),
		m_closingTimeoutState(new ClosingTimeoutState(5)),
		m_closedState(new ClosedState(6)),

		// Current one
		m_currentState(0),
		m_movingDoorTimer(0UL),
		m_notClosedDoorTimer(0UL),
		m_isForgottenOpenedDoor(false)

{
	// Set listeners
	IOManager::getInstance()->m_button->setListener(&DoorStateManager::buttonPressed);
	IOManager::getInstance()->m_bottomHallSensor->setListener(&DoorStateManager::bottomTouched);
	IOManager::getInstance()->m_topHallSensor->setListener(&DoorStateManager::topTouched);
	IOManager::getInstance()->m_photoElecBeam->setListener(&DoorStateManager::photoElecCut);

	// Compute initial state
	if (IOManager::getInstance()->m_bottomHallSensor->getState()) {
		stateChanged(m_closedState);
	} else if (IOManager::getInstance()->m_topHallSensor->getState()) {
		stateChanged(m_openedState);
	} else {
		stateChanged(m_unknownState);
	}
}

void DoorStateManager::buttonPressed(bool const oldState, bool const newState) {
	if (newState) {
		IOManager::getInstance()->m_relay->toggleFor();
	}
}

void DoorStateManager::bottomTouched(bool const oldState, bool const newState) {
	if (newState) {
		getInstance()->stateChanged(getInstance()->m_closedState);
	} else {
		getInstance()->stateChanged(getInstance()->m_openingState);
	}
}

void DoorStateManager::topTouched(bool const oldState, bool const newState) {
	if (newState) {
		getInstance()->stateChanged(getInstance()->m_openedState);
	} else {
		getInstance()->stateChanged(getInstance()->m_closingState);
	}
}

void DoorStateManager::photoElecCut(bool const oldState, bool const newState) {
	if (getInstance()->m_currentState == getInstance()->m_openedState) {
		IOManager::getInstance()->m_yellow->setState(
				IOManager::getInstance()->m_photoElecBeamPower->getState() && newState);
	}
}

const bool DoorStateManager::isObstacleDetected() {
	return (m_currentState == m_openedState) && IOManager::getInstance()->m_photoElecBeamPower->getState()
			&& IOManager::getInstance()->m_photoElecBeam->getState();
}

//----------------------------------------------------------------------------------------------------
// State machine. Called once by state switching (Manage non-blinking led switching, timers and tweets)
void DoorStateManager::stateChanged(AbstractDoorState * const newState) {
	AbstractDoorState * const oldState = m_currentState;
	m_currentState = newState;
#ifdef PRINT_DEBUG_MSGS
	Serial.print("State changed: ");
	Serial.print(oldState);
	Serial.print(" -> ");
	Serial.println(newState);
#endif
	newState->activate(m_notClosedDoorTimer, m_movingDoorTimer, m_isForgottenOpenedDoor);
	const char* tweetMsg = newState->getTweetMessage();
	if (tweetMsg && shouldTweetThisTransition(oldState, newState)) {
		IOManager::getInstance()->m_doorTwitter->tweet(tweetMsg);
	}
}

void DoorStateManager::update(unsigned long currentTime) {
	IOManager::getInstance()->update(currentTime);

	// Check for forgotten opened door (alarm notification)
	if (m_notClosedDoorTimer > 0UL && (currentTime - m_notClosedDoorTimer > FORGOTTEN_DOOR_DELAY_BEFORE_NOTIF)) {
		IOManager::getInstance()->m_doorTwitter->tweet(
				IOManager::getInstance()->m_sentencesFile->m_forgottenOpenedDoorTimeOutMsg);
		// Disable timer
		m_notClosedDoorTimer = 0UL;
		m_isForgottenOpenedDoor = true;
	}

	// Check for opening or closing timeout to put the "interrupted opening or closed" state
	if (m_movingDoorTimer > 0UL) {
		if (m_currentState == m_openingState && (currentTime - m_movingDoorTimer > MAX_OPENING_DURATION)) {
			stateChanged(m_openingTimeoutState);
		} else if (m_currentState == m_closingState && (currentTime - m_movingDoorTimer > MAX_CLOSING_DURATION)) {
			stateChanged(m_closingTimeoutState);
		}
	}
}

const bool DoorStateManager::isForgottenOpenedDoor() {
	return m_isForgottenOpenedDoor;
}

bool DoorStateManager::shouldTweetThisTransition(AbstractDoorState* const oldState, AbstractDoorState* const newState) {
	// Tweet opened state if this state is not expected (door stopped and go back or moving timeout)
	if (oldState == 0 || oldState == m_unknownState || oldState == m_openingTimeoutState || oldState == m_closingTimeoutState) {
		return true;
	}
	if (newState == m_openedState) {
		return oldState == m_closingState;
	}
	if (newState == m_closedState) {
		return oldState == m_openingState;
	}
	return true;
}
