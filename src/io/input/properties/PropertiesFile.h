/*
 * PropertiesFile.h
 *
 *  Created on: 24 mai 2014
 *      Author: nicolaslambert
 */

#ifndef PROPERTIESFILE_H_
#define PROPERTIESFILE_H_

#include <SD.h>

class PropertiesFile {
public:
	PropertiesFile();
protected:
	char const * const * const readValues(char const * const path, char const * const keys[], int const varCount);
};

#endif /* PROPERTIESFILE_H_ */
