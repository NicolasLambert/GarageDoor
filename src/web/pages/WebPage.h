/*
 * WebPage.h
 *
 *  Created on: 13 mai 2014
 *      Author: nicolaslambert
 */

#ifndef WEBPAGE_H_
#define WEBPAGE_H_

#include <SD.h>
#include "../../../Libraries/Webduino/WebServer.h" // Webduino for http management: https://github.com/sirleech/Webduino/

class WebPage {
public:
	WebPage(WebServer * const webServer, char const * const path);
	void print();
private:
	WebServer * const m_webServer;
	File m_file;
};

#endif /* WEBPAGE_H_ */
