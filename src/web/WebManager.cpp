/*
 * WebManager.cpp
 *
 *  Created on: 30 mai 2014
 *      Author: nicolaslambert
 */

#include "WebManager.h"

//#define PRINT_DEBUG_MSGS

WebManager::WebManager() :
		m_webserver(new WebServer("", 80)), m_mainPage(new MainPage(m_webserver)) {
	m_webserver->setDefaultCommand(&webPageCmd);
	m_webserver->addCommand("index.html", &webPageCmd);
	m_webserver->addCommand("ajax_refresh", &getStateCmd);
	m_webserver->addCommand("ajax_action", &pushButtonCmd);
	m_webserver->begin();

}

void WebManager::update() {
	char buff[64];
	int len = 64;

	/* process incoming connections one at a time forever */
	m_webserver->processConnection(buff, &len);
}

//----------------------------------------------------------------------------------------------------
// This function is called by webserver (by pointer on function). It manage http request
void WebManager::webPageCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete) {
#ifdef PRINT_DEBUG_MSGS
	Serial.println("Index");
#endif
	if (getInstance()->m_webserver->checkCredentials(IOManager::getInstance()->m_credentialsFile->m_authCredentials)) {
		/* for a GET or HEAD, send the standard "it's all OK headers" */
		server.httpSuccess();

		/* we don't output the body for a HEAD request */
		if (type != WebServer::HEAD) {
			getInstance()->m_mainPage->print();
		}
	} else {
		/* send a 401 error back causing the web browser to prompt the user for credentials */
		server.httpUnauthorized();
	}
}

void WebManager::getStateCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete) {
#ifdef PRINT_DEBUG_MSGS
	Serial.println("ajax_refresh");
#endif
	if (getInstance()->m_webserver->checkCredentials(IOManager::getInstance()->m_credentialsFile->m_authCredentials)) {
		/* for a GET or HEAD, send the standard "it's all OK headers" */
		server.httpSuccess();
		server.print("{'state': ");
		server.print(DoorStateManager::getInstance()->m_currentState->getId());
		server.print(", 'obstacle': ");
		server.print(DoorStateManager::getInstance()->isObstacleDetected() ? "true" : "false");
		server.print(", 'forgottenOpened': ");
		server.print(DoorStateManager::getInstance()->isForgottenOpenedDoor() ? "true" : "false");
		server.print('}');
	} else {
		/* send a 401 error back causing the web browser to prompt the user for credentials */
		server.httpUnauthorized();
	}
}

void WebManager::pushButtonCmd(WebServer& server, WebServer::ConnectionType type, char* url_tail, bool tail_complete) {
#ifdef PRINT_DEBUG_MSGS
	Serial.println("ajax_action");
#endif
	if (getInstance()->m_webserver->checkCredentials(IOManager::getInstance()->m_credentialsFile->m_authCredentials)) {
		if (type == WebServer::POST) {
			IOManager::getInstance()->m_actionDoorCmd->toggleFor();
		}

		/* for a GET or HEAD, send the standard "it's all OK headers" */
		server.httpSuccess();
	} else {
		/* send a 401 error back causing the web browser to prompt the user for credentials */
		server.httpUnauthorized();
	}
}
