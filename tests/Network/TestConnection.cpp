/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 14:36:55 CEST 2016
 */

#include "TestConnection.h"
using namespace std;

TestConnection::TestConnection() :
	partner(NULL)
{
}

TestConnection::~TestConnection() {
}

void TestConnection::pair(TestConnection &connection) {
	partner = &connection;
}

void TestConnection::read(Receiver &receiver, size_t bytes) {
	PendingReceiver pendingReceiver;

	pendingReceiver.receiver = &receiver;
	pendingReceiver.bytes = bytes;

	pendingReceivers.push(pendingReceiver);

	consumeBuffer();
}

void TestConnection::write(Sender & sender, const char * data, size_t bytes) {
	partner->receive(data, bytes);
	sender.sent(data, bytes);

}

void TestConnection::receive(const char *data, size_t bytes) {
	buffer += string(data, bytes);

	consumeBuffer();
}

void TestConnection::consumeBuffer() {

	while(!pendingReceivers.empty() 
			&& pendingReceivers.front().bytes <= buffer.length()) {
		size_t partLength = pendingReceivers.front().bytes;

		string partBuffer(buffer.begin(), buffer.begin()+partLength);
		buffer.erase(buffer.begin(), buffer.begin()+partLength);

		pendingReceivers.front().receiver->receive(partBuffer.data(), partLength);
		pendingReceivers.pop();
	}

}

