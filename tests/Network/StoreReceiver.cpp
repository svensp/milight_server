/**
 * Created by cmd-keen
 * on netbook
 * at Mo 13. Jun 00:17:33 CEST 2016
 */

#include "StoreReceiver.h"
using namespace std;

StoreReceiver::StoreReceiver() :
	wasCalled(false)
{
}

StoreReceiver::~StoreReceiver() {
}

void StoreReceiver::receive(const char * data, size_t size) {
	lastReceivedData = string(data, size);
	sizeReceived = size;
	wasCalled = true;
}

std::string StoreReceiver::getDataReceived() {
	return lastReceivedData;
}

size_t StoreReceiver::getSizeReceived() {
	return sizeReceived;
}

bool StoreReceiver::isCalled() {
	return wasCalled;
}

void StoreReceiver::resetCalled() {
	wasCalled=false;
}

