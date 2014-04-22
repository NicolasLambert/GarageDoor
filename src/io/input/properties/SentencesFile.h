/*
 * SentencesFile.h
 *
 *  Created on: 24 mai 2014
 *      Author: nicolaslambert
 */

#ifndef SENTENCESFILE_H_
#define SENTENCESFILE_H_

#include "PropertiesFile.h"

class SentencesFile: public PropertiesFile {
public:
	SentencesFile();
	char const * m_unknownMsg;
	char const * m_openingMsg;
	char const * m_openingTimeOutMsg;
	char const * m_openedMsg;
	char const * m_closingMsg;
	char const * m_closingTimeOutMsg;
	char const * m_closedMsg;
	char const * m_forgottenOpenedDoorTimeOutMsg;
};

#endif /* SENTENCESFILE_H_ */
