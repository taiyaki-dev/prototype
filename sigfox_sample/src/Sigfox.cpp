#include "Arduino.h"
#include <SoftwareSerial.h>
#include "Sigfox.hpp"

#define RX_PIN_SIGFOX 5
#define TX_PIN_SIGFOX 4

#define BAUDRATE_SIGFOX 9600

#define GET_DEVICE_ID "AT$I=10"		// Get Sigfox Device ID
#define SET_UL_FREQUENCY "AT$IF=923200000"	// Set Uplink Frequency (923.2MHz)
#define SET_DL_FREQUENCY "AT$DR=922200000"	// Set Downlink Frequency (922.2MHz)
#define SET_PUBLICKEY_MODE "ATS410=0"		// Set Public Key Mode
#define SAVE_CONFIG "AT$WR"			// Save Cofig
#define SEND_MESSAGE "AT$SF="
#define TERMINATION "\r"

SoftwareSerial serial_sigfox =  SoftwareSerial(RX_PIN_SIGFOX, TX_PIN_SIGFOX);

bool SendCommand(const String command){
	bool ret = false;
	
	serial_sigfox.print(command);
	serial_sigfox.print(TERMINATION);
	
	delay(100);
	
	ret = true;
	return ret;
}

bool Sigfox::Initialize(){
	bool ret = false;
  
	serial_sigfox.begin(BAUDRATE_SIGFOX);
	SendCommand(GET_DEVICE_ID);
	SendCommand(SET_UL_FREQUENCY);
	SendCommand(SET_DL_FREQUENCY);
	SendCommand(SET_PUBLICKEY_MODE);
	SendCommand(SAVE_CONFIG);
	
	ret = true;
	return ret;
}

bool Sigfox::SendMessage(const String message){
	bool ret = false;
	
	SendCommand(SEND_MESSAGE + message + TERMINATION);
	/*
	while(true){

		if(status.length()){
			delay(60000);
			break;
		}
		delay(100);
	}
	*/
	
	ret =  true;
	return ret;
}

bool Sigfox::Finalize(){
  bool ret = false;

  ret = true;
  return ret;
}
