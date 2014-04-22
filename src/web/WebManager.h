/*
 * WebManager.h
 *
 *  Created on: 30 mai 2014
 *      Author: nicolaslambert
 */

#ifndef WEBMANAGER_H_
#define WEBMANAGER_H_

#include "../../Libraries/Webduino/WebServer.h" // Webduino for http management: https://github.com/sirleech/Webduino/
#include "pages/MainPage.h"
#include "../io/input/properties/CredentialsFile.h"
#include "../states/DoorStateManager.h"

class WebManager: public AbstractManager<WebManager> {
public:
	WebManager();
	void update();
private:
	WebServer * m_webserver;
	MainPage * m_mainPage;
	static void webPageCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
	static void getStateCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
	static void pushButtonCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete);
};

#endif /* WEBMANAGER_H_ */
