/*
 * DoorTwitter.h
 *
 *  Created on: 29 mai 2014
 *      Author: nicolaslambert
 */

#ifndef DOORTWITTER_H_
#define DOORTWITTER_H_

#include "../input/properties/CredentialsFile.h"
#include "../../../Libraries/Twitter/Twitter.h"

#define STATE1_NOTHING_TO_DO 0
#define STATE2_MSG_TO_POST   1
#define STATE3_WAITING_ACK   2
#define TWEET_ANTI_FLOOD_DELAY 5000UL

class DoorTwitter {
public:
	DoorTwitter(char const * const twitterToken);
	void tweet(char const * const msg);
	void update(unsigned long currentTime);
private:
	Twitter * const m_twitter;
	int m_currentState;
	char m_msgBuffer[128];
	unsigned long m_lastTweetTry;
};

#endif /* DOORTWITTER_H_ */
