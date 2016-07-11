/**
 * Created by cmd-keen
 * on netbook
 * at So 10. Jul 08:13:37 CEST 2016
 */

#ifndef _PACKETSPECIFICSENDER_H_
#define _PACKETSPECIFICSENDER_H_

#include "../Connection.h"
#include "../Packet.h"

/**
 * @brief 
 */
class PacketSpecificSender {
public:
	virtual ~PacketSpecificSender();
	virtual void send(Connection &connection, Packet::Ptr packet) = 0;
};

#endif
