/*
 * DoorTwitter.cpp
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#include "DoorTwitter.h"

DoorTwitter::DoorTwitter(char const * const twitterToken) :
		m_twitter(new Twitter(twitterToken)), m_currentState(STATE1_NOTHING_TO_DO), m_lastTweetTry(0UL) {
	randomSeed(analogRead(A10));
}

#define ENABLE_TWEET
//#define PRINT_DEBUG_MSGS

void DoorTwitter::tweet(const char* const msg) {
	// Append millis for information
	// Append random to avoid duplicate msg twitter error (403)
	sprintf(m_msgBuffer, "%s (%lu/%ld)", msg, millis(), random(0, 100));
	m_currentState = STATE2_MSG_TO_POST;
}

void DoorTwitter::update(unsigned long currentTime) {
#ifdef ENABLE_TWEET
	if (m_currentState == STATE2_MSG_TO_POST && (m_lastTweetTry + TWEET_ANTI_FLOOD_DELAY < currentTime)) {
		// Send message
#ifdef PRINT_DEBUG_MSGS
		Serial.print("Try to tweet: ");
		Serial.println(m_msgBuffer);
#endif
		m_twitter->checkStatus(0);
		m_lastTweetTry = currentTime;
		if (m_twitter->post(m_msgBuffer)) {
			m_currentState = STATE3_WAITING_ACK;
		}
#ifdef PRINT_DEBUG_MSGS
		else {
			Serial.println("connection failed.");
		}
#endif
	}
	if (m_currentState == STATE3_WAITING_ACK && !(m_twitter->checkStatus(0))) {
		if (m_twitter->status() == 200) {
			m_currentState = STATE1_NOTHING_TO_DO;
#ifdef PRINT_DEBUG_MSGS
			Serial.println("Ack: OK.");
#endif
		} else {
			m_currentState = STATE2_MSG_TO_POST;
#ifdef PRINT_DEBUG_MSGS
			Serial.print("Ack: failed with code ");
			Serial.println(m_twitter->status());
#endif
		}
	}
#else
#ifdef PRINT_DEBUG_MSGS
	if (m_currentState==STATE2_MSG_TO_POST) {
		Serial.print("Fake tweet: ");
		Serial.println(m_msgBuffer);
		m_currentState = STATE1_NOTHING_TO_DO;
	}
#endif
#endif
}
