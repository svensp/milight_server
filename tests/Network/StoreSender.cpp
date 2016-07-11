/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 15:08:59 CEST 2016
 */

#include "StoreSender.h"
using namespace std;

StoreSender::StoreSender() :
	sentCalled(false)
{
}

StoreSender::~StoreSender() {
}

void StoreSender::sent(const char *data, size_t bytes) {
	this->lastSent = string(data, bytes);
	sentCalled = true;
}

bool StoreSender::wasCalled() {
	return this->sentCalled;
}

std::string StoreSender::dataSent() {
	return lastSent;
}

