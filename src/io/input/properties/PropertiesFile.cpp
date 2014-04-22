/*
 * PropertiesFile.cpp
 *
 *  Created on: 24 mai 2014
 *      Author: nicolaslambert
 */

#include "PropertiesFile.h"

PropertiesFile::PropertiesFile() {
}

//#define PRINT_DEBUG_MSGS

char const * const * const PropertiesFile::readValues(char const * const path, char const * const keys[],
		int const varCount) {
#ifdef PRINT_DEBUG_MSGS
	Serial.print("Read ");
	Serial.println(path);
#endif
	File file = SD.open(path);
	if (file) {
		char const * values[varCount];
		String key = "";
		String value = "";
		bool isInValue = false;
		char oneChar;
		while (file.available()) {
			oneChar = file.read();
			switch (oneChar) {
			case '=':
				if (isInValue) {
					// we are already in value mode, put this '=' char in the value
					value += oneChar;
				} else {
					// Fist '=' on the line, go in value mode
					isInValue = true;
				}
				break;
			case '\n':
#ifdef PRINT_DEBUG_MSGS
				Serial.print("key:");
				Serial.print(key);
#endif
				isInValue = false;
				for (int i = 0; i < varCount; i++) {
					if (key.equals(keys[i])) {
						values[i] = strdup(value.c_str());
#ifdef PRINT_DEBUG_MSGS
						Serial.print(" value:");
						Serial.println(values[i]);
#endif
						break;
					}
				}
				key = "";
				value = "";
				break;
			default:
				if (isInValue) {
					value += oneChar;
				} else {
					key += oneChar;
				}
				break;
			}
		}
		file.close();
		return values;
	}
	return 0;
}
