/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 14:35:31 CEST 2016
 */

#ifndef _TESTCONNECTION_H_
#define _TESTCONNECTION_H_

#include <Network/Connection.h>
#include <queue>
#include <string>

struct PendingReceiver {
	Receiver *receiver;
	size_t bytes;
};

/**
 * @brief 
 */
class TestConnection : public Connection {
protected:
	TestConnection *partner;
	typedef std::queue<PendingReceiver> PendingReceivers;
	PendingReceivers pendingReceivers;
	std::string buffer;

	void consumeBuffer();
public:
	TestConnection();
	virtual ~TestConnection();
	void pair(TestConnection &connection);
	void receive(const char *data, size_t bytes);
	virtual void read(Receiver &receiver, size_t bytes);
	virtual void write(Sender &sender, const char *data, size_t bytes);
};

#endif
