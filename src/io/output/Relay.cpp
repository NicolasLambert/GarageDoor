/*
 * Relay.cpp
 *
 *  Created on: 12 mai 2014
 *      Author: nicolaslambert
 */

#include "Relay.h"

Relay::Relay(int const pin) :
		DigitalOutput(pin, true), m_maintainUntil(0UL) {
}

void Relay::toggleFor(unsigned int delay) {
	if (m_maintainUntil == 0UL) {
		toggle();
	}
	m_maintainUntil = millis() + delay;
}

void Relay::on() {
	DigitalOutput::on();
	m_maintainUntil = 0UL;
}

void Relay::off() {
	DigitalOutput::off();
	m_maintainUntil = 0UL;
}

void Relay::update(unsigned long currentTime) {
	if (m_maintainUntil > 0 && currentTime > m_maintainUntil) {
		m_maintainUntil = 0UL;
		toggle();
	}
}
