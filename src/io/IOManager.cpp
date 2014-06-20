/*
 * IOManager.cpp
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#include "IOManager.h"

IOManager::IOManager() :
		//----------------------------------------------------------------------------------------------------
		// Inputs
		m_actionDoorButton(new Button(54)),	//A0
		m_bottomLimitSensor(new Button(55, 300)),	//A1
		m_topLimitSensor(new Button(56)),	//A2
		m_photoElecBeam(new Button(57)),	//A3
		//----------------------------------------------------------------------------------------------------
		// Outputs
		m_actionDoorCmd(new Relay(7)),
		m_photoElecBeamPower(new Relay(8)),
		m_redLed(new Led(3)),
		m_yellowLed(new Led(5)),
		m_greenLed(new Led(6))
{
	// Start setup
	m_redLed->on();
	m_yellowLed->on();
	m_greenLed->on();
	delay(500);

	// disable w5100 SPI while setting up SD
	pinMode(W5100_SPI, OUTPUT);
	digitalWrite(W5100_SPI, HIGH);

	// initialize the SD card
	m_redLed->off();
	while (!SD.begin(SD_PIN)) {
		m_redLed->on();
		delay(500);
		m_redLed->off();
	};

	m_credentialsFile = new CredentialsFile();
	m_sentencesFile = new SentencesFile();

	// Configure Ethernet Connection (w5100)
	m_yellowLed->off();
	uint8_t mac[6] = { 0x90, 0xA2, 0xDA, 0x0D, 0xFA, 0x43 };
	while (Ethernet.begin(mac) == 0) {
		m_yellowLed->on();
		delay(500);
		m_yellowLed->off();
	};

	// Let the Ethernet shield initialize
	digitalWrite(W5100_SPI,HIGH);
	delay(2000);

	m_doorTwitter = new DoorTwitter(m_credentialsFile->m_twitterToken);

	m_greenLed->off();
}

void IOManager::update(unsigned long currentTime) {
	m_actionDoorButton->update(currentTime);
	m_bottomLimitSensor->update(currentTime);
	m_topLimitSensor->update(currentTime);
	m_photoElecBeam->update(currentTime);
	m_actionDoorCmd->update(currentTime);
	m_photoElecBeamPower->update(currentTime);
	m_redLed->update(currentTime);
	m_yellowLed->update(currentTime);
	m_greenLed->update(currentTime);
	m_doorTwitter->update(currentTime);
}
