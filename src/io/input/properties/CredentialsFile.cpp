/*
 * CredentialsFile.cpp
 *
 *  Created on: 26 mai 2014
 *      Author: nicolaslambert
 */

#include "CredentialsFile.h"

CredentialsFile::CredentialsFile() :
		PropertiesFile() {
	int const varCount = 2;
	char const * keys[varCount] = { "AUTH_CREDENTIALS", "TWITTER_TOKEN" };
	char const * const * const values = readValues("credent.txt", keys, varCount);
	int i = 0;
	m_authCredentials = values[i++];
	m_twitterToken = values[i++];
}

