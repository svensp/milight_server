/**
 * Created by cmd-keen
 * on netbook
 * at Sa 9. Jul 23:46:12 CEST 2016
 */

#include "PacketWriter.h"
#include "HeaderSentPacketSender.h"

PacketWriter::~PacketWriter() {
}

PacketWriter::PacketWriter(HeaderWriter &_headerWriter, SenderFactory &_senderFactory) :
	headerWriter(_headerWriter),
	senderFactory(_senderFactory)
{
}

void PacketWriter::write(Connection &connection, Packet::Ptr packet) {
	SenderFactory::SenderPtr sender = senderFactory.makeSender( packet->getType() );
	Sender::SenderPtr packetSender(
			new HeaderSentPacketSender(connection, std::move(sender), packet)
			);
	headerWriter.write(connection, packet, std::move(packetSender) );
}

