/*
  EthernetStreamW5100.h - Streaming Ethernet Arduino library for W5100-based ethernet shield
  Copyright (c) 2012 Anton Smirnov (dev@antonsmirnov.name)
*/

#ifndef ETHERNET_STREAM_W5100
#define ETHERNET_STREAM_W5100

#include <inttypes.h>
#include <Stream.h>
#include <Ethernet.h>

class EthernetStream : public Stream
{
	private:
		EthernetServer *server;
		EthernetClient client;
  	
  public:		
			// begin with dynamic IP:port (DHCP)
			// Returns 0 if the DHCP configuration failed, and 1 if it succeeded
		  int begin(uint8_t *mac_address, uint16_t port);
			
			// begin with static IP:port
      void begin(uint8_t *mac_address, IPAddress local_ip, uint16_t port);
		
			// get DCHP IP
			IPAddress localIP();
		
			// overriden Stream class functions
			virtual size_t write(uint8_t byte);
			virtual int read();
			virtual int available();
			virtual void flush();
			virtual int peek();	  
};

#endif

