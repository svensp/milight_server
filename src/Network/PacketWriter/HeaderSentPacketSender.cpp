/**
 * Created by cmd-keen
 * on netbook
 * at So 10. Jul 16:50:50 CEST 2016
 */

#include "HeaderSentPacketSender.h"

HeaderSentPacketSender::~HeaderSentPacketSender() {
}

void HeaderSentPacketSender::sent(const char *data, size_t bytes) {
	sender->send(connection, packet);
}

HeaderSentPacketSender::HeaderSentPacketSender(Connection &_connection, SenderFactory::SenderPtr _sender, Packet::Ptr &_packet) :
	connection(_connection),
	sender( std::move(_sender) ),
	packet(_packet)
{
}

