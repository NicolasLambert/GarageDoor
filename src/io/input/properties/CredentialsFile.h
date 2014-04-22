/*
 * CredentialsFile.h
 *
 *  Created on: 26 mai 2014
 *      Author: nicolaslambert
 */

#ifndef CREDENTIALSFILE_H_
#define CREDENTIALSFILE_H_

#include "PropertiesFile.h"

class CredentialsFile: public PropertiesFile {
public:
	CredentialsFile();
	char const * m_authCredentials;
	char const * m_twitterToken; // Twitter token. See http://arduino-tweet.appspot.com/
};

#endif /* CREDENTIALSFILE_H_ */
