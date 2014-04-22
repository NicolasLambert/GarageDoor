/*
 * WebPage.cpp
 *
 *  Created on: 13 mai 2014
 *      Author: nicolaslambert
 */

#include "WebPage.h"

WebPage::WebPage(WebServer * const webServer, char const * const path) :
		m_webServer(webServer), m_file(SD.open(path)) {
}

void WebPage::print() {
	if (m_file.seek(0)) {
		String currentVar = "";
		bool inVariable = false;
		char oneChar;
		while (m_file.available()) {
			oneChar = m_file.read();
			m_webServer->print(oneChar);
		}
	}
}
