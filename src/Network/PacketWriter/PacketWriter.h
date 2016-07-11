/**
 * Created by cmd-keen
 * on netbook
 * at Sa 9. Jul 22:49:05 CEST 2016
 */

#ifndef _PACKETWRITER_H_
#define _PACKETWRITER_H_

#include "HeaderWriter.h"
#include "SenderFactory.h"
#include "../Connection.h"
#include "../Packet.h"

/**
 * @brief Writes a header, then a packet through a connection
 */
class PacketWriter {
protected:
	HeaderWriter &headerWriter;
	SenderFactory &senderFactory;
public:
	PacketWriter(HeaderWriter &headerWriter, SenderFactory &senderFactory);
	virtual ~PacketWriter();
	void write(Connection &connection, Packet::Ptr packet);
};

#endif
