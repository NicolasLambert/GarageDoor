/*
 * IOManager.h
 *
 *  Created on: 27 mai 2014
 *      Author: nicolaslambert
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include "../AbstractManager.h"
#include "input/Button.h"
#include "output/Led.h"
#include "output/Relay.h"
#include "output/DoorTwitter.h"
#include "input/properties/SentencesFile.h"
#include "input/properties/CredentialsFile.h"

// Variables for ethernet connection
#define SD_PIN 4
#define W5100_SPI 53 //53 on mega, 10 on others

class IOManager: public AbstractManager<IOManager> {
public:
	IOManager();
	void update(unsigned long currentTime);

	//----------------------------------------------------------------------------------------------------
	// Inputs
	Button * m_actionDoorButton;
	Button * m_bottomLimitSensor;
	Button * m_topLimitSensor;
	Button * m_photoElecBeam;
	CredentialsFile * m_credentialsFile;
	SentencesFile * m_sentencesFile;

	//----------------------------------------------------------------------------------------------------
	// Outputs
	Relay * m_actionDoorCmd;
	Relay * m_photoElecBeamPower;
	Led * m_redLed;
	Led * m_yellowLed;
	Led * m_greenLed;
	DoorTwitter * m_doorTwitter;
};

#endif /* IOMANAGER_H_ */
