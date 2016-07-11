/**
 * Created by cmd-keen
 * on netbook
 * at So 10. Jul 08:14:34 CEST 2016
 */

#ifndef _SENDERFACTORY_H_
#define _SENDERFACTORY_H_

#include "PacketSpecificSender.h"
#include <memory>
#include "../Packet.h"

/**
 * @brief 
 */
class SenderFactory {
public:
	typedef std::unique_ptr<PacketSpecificSender> SenderPtr;
	virtual ~SenderFactory();
	virtual SenderPtr makeSender(Packet::Type type) = 0;
};

#endif
