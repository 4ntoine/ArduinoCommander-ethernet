/*
  EthernetStreamW5100.cpp - Streaming Ethernet Arduino library for W5100-based ethernet shield
  Copyright (c) 2012 Anton Smirnov (dev@antonsmirnov.name)
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <EthernetStreamW5100.h>
#include <Arduino.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/

int EthernetStream::begin(uint8_t *mac_address, uint16_t port)
{
	// start DHCP and check result
	int result = Ethernet.begin(mac_address);
	if (result == 0)
		return 0;
		
  server = new EthernetServer(port);
	server->begin();
	return result;  
}

void EthernetStream::begin(uint8_t *mac_address, IPAddress local_ip, uint16_t port)
{
	Ethernet.begin(mac_address, local_ip);
	server = new EthernetServer(port);
	server->begin();
}

IPAddress EthernetStream::localIP()
{
	return Ethernet.localIP();
}

int EthernetStream::available()
{
		EthernetClient newClient = server->available();
		if (!newClient)			
			return 0;
		
		client = newClient;		
		return client.connected() ? client.available() : 0;
}

int EthernetStream::read()
{
		return client.read();
}

void EthernetStream::flush() {
    client.flush();
}

int EthernetStream::peek() {
    client.peek();
}

size_t EthernetStream::write(uint8_t outcomingByte) {	
		client.write(outcomingByte);
}