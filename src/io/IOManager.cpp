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
		m_button(new Button(54)),	//A0
		m_bottomHallSensor(new Button(55, 300)),	//A1
		m_topHallSensor(new Button(56)),	//A2
		m_photoElecBeam(new Button(57)),	//A3
		//----------------------------------------------------------------------------------------------------
		// Outputs
		m_relay(new Relay(7)),
		m_photoElecBeamPower(new Relay(8)),
		m_red(new Led(3)),
		m_yellow(new Led(5)),
		m_green(new Led(6))
{
	// Start setup
	m_red->on();
	m_yellow->on();
	m_green->on();
	delay(500);

	// disable w5100 SPI while setting up SD
	pinMode(W5100_SPI, OUTPUT);
	digitalWrite(W5100_SPI, HIGH);

	// initialize the SD card
	m_red->off();
	while (!SD.begin(SD_PIN)) {
		m_red->on();
		delay(500);
		m_red->off();
	};

	m_credentialsFile = new CredentialsFile();
	m_sentencesFile = new SentencesFile();

	// Configure Ethernet Connection (w5100)
	m_yellow->off();
	uint8_t mac[6] = { 0x90, 0xA2, 0xDA, 0x0D, 0xFA, 0x43 };
	while (Ethernet.begin(mac) == 0) {
		m_yellow->on();
		delay(500);
		m_yellow->off();
	};

	// Let the Ethernet shield initialize
	digitalWrite(W5100_SPI,HIGH);
	delay(2000);

	m_doorTwitter = new DoorTwitter(m_credentialsFile->m_twitterToken);

	m_green->off();
}

void IOManager::update(unsigned long currentTime) {
	m_button->update(currentTime);
	m_bottomHallSensor->update(currentTime);
	m_topHallSensor->update(currentTime);
	m_photoElecBeam->update(currentTime);
	m_relay->update(currentTime);
	m_photoElecBeamPower->update(currentTime);
	m_red->update(currentTime);
	m_yellow->update(currentTime);
	m_green->update(currentTime);
	m_doorTwitter->update(currentTime);
}
