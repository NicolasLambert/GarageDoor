/*
 * DoorStateManager.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DOORSTATEMANAGER_H_
#define DOORSTATEMANAGER_H_

#include "../io/IOManager.h"
#include "UnknownState.h"
#include "open/OpeningState.h"
#include "open/OpeningTimeoutState.h"
#include "open/OpenedState.h"
#include "close/ClosingState.h"
#include "close/ClosingTimeoutState.h"
#include "close/ClosedState.h"

#define FORGOTTEN_DOOR_DELAY_BEFORE_NOTIF 15UL * 60UL * 1000UL // interval at which to notify that door is opened (15m*60s/m*1000ms/s)
#define MAX_OPENING_DURATION 15543UL // After this delay (ms) a msg is sent saying the door have probably been stopped
#define MAX_CLOSING_DURATION 22185UL // After this delay (ms) a msg is sent saying the door have probably been stopped

class DoorStateManager: public AbstractManager<DoorStateManager> {
public:
	// Listener methods
	DoorStateManager();
	static void buttonPressed(bool const oldState, bool const newState);
	static void bottomTouched(bool const oldState, bool const newState);
	static void topTouched(bool const oldState, bool const newState);
	static void photoElecCut(bool const oldState, bool const newState);
	void update(unsigned long currentTime);
	bool const isObstacleDetected();
	bool const isForgottenOpenedDoor();
	AbstractDoorState * m_currentState;

private:
	// States members
	UnknownState * m_unknownState;
	OpeningState * m_openingState;
	OpeningTimeoutState * m_openingTimeoutState;
	OpenedState * m_openedState;
	ClosingState * m_closingState;
	ClosingTimeoutState * m_closingTimeoutState;
	ClosedState * m_closedState;

	// Current State
	unsigned long m_notClosedDoorTimer; // will store last time door was not closed
	unsigned long m_movingDoorTimer; // will store last time door was opened or closed
	bool m_isForgottenOpenedDoor; // true if the door is not closed since more than the max alarm delay

	// Change state method
	void stateChanged(AbstractDoorState * const newState);
	bool shouldTweetThisTransition(AbstractDoorState * const oldState, AbstractDoorState * const newState);
};

#endif /* DOORSTATEMANAGER_H_ */
