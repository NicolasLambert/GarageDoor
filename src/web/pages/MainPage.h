/*
 * MainPage.h
 *
 *  Created on: 13 mai 2014
 *      Author: nicolaslambert
 */

#ifndef MAINPAGE_H_
#define MAINPAGE_H_

#include "WebPage.h"

class MainPage: public WebPage {
public:
	MainPage(WebServer * const webServer);
};

#endif /* MAINPAGE_H_ */
