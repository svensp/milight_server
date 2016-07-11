/**
 * Created by cmd-keen
 * on netbook
 * at Sa 9. Jul 23:43:27 CEST 2016
 */

#ifndef _HEADERWRITER_H_
#define _HEADERWRITER_H_

#include "../Connection.h"
#include "../Packet.h"
#include "../Sender.h"

/**
 * @brief 
 */
class HeaderWriter {
public:
	virtual ~HeaderWriter();
	virtual void write(Connection &connection, Packet::Ptr packet, Sender::SenderPtr sender) = 0;
};

#endif
