/**
 * Created by cmd-keen
 * on netbook
 * at Mo 13. Jun 00:15:56 CEST 2016
 */

#ifndef _STORERECEIVER_H_
#define _STORERECEIVER_H_

#include <Network/Receiver.h>
#include <string>

/**
 * @brief 
 */
class StoreReceiver : public Receiver {
protected:
	std::string lastReceivedData;
	size_t sizeReceived;
	bool wasCalled;
public:
	StoreReceiver();
	virtual ~StoreReceiver();
	virtual void receive(const char *data, size_t size);
	std::string getDataReceived();
	size_t getSizeReceived();
	bool isCalled();
	void resetCalled();
};

#endif
