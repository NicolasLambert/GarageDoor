/*
 * SentencesFile.cpp
 *
 *  Created on: 24 mai 2014
 *      Author: nicolaslambert
 */

#include "SentencesFile.h"

SentencesFile::SentencesFile() :
		PropertiesFile() {
	int const varCount = 9;
	char const * keys[varCount] = {
			"UNKNOWN_MSG",
			"OPENING_MSG",
			"OPENING_TIMEOUT_MSG",
			"OPENED_MSG",
			"CLOSING_MSG",
			"CLOSING_TIMEOUT_MSG",
			"CLOSED_MSG",
			"FORGOTTEN_OPENED_DOOR_TIMEOUT_MSG"
	};
	char const * const * const values = readValues("sentence.txt", keys, varCount);
	int i = 0;
	m_unknownMsg = values[i++];
	m_openingMsg = values[i++];
	m_openingTimeOutMsg = values[i++];
	m_openedMsg = values[i++];
	m_closingMsg = values[i++];
	m_closingTimeOutMsg = values[i++];
	m_closedMsg = values[i++];
	m_forgottenOpenedDoorTimeOutMsg = values[i++];
}

