/**
 * Created by cmd-keen
 * on netbook
 * at So 10. Jul 16:49:34 CEST 2016
 */

#ifndef _HEADERSENTPACKETSENDER_H_
#define _HEADERSENTPACKETSENDER_H_

#include "../Sender.h"
#include "SenderFactory.h"

/**
 * @brief 
 */
class HeaderSentPacketSender : public Sender {
protected:
	Connection &connection;
	SenderFactory::SenderPtr sender;
	Packet::Ptr &packet;
public:
	HeaderSentPacketSender(Connection &connection, SenderFactory::SenderPtr sender, Packet::Ptr &packet);
	virtual ~HeaderSentPacketSender();
	virtual void sent(const char *data, size_t bytes);
};

#endif
