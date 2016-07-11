/**
 * Created by cmd-keen
 * on netbook
 * at Sa 9. Jul 22:49:29 CEST 2016
 */

#ifndef _PACKET_H_
#define _PACKET_H_

#include <cstdlib>
#include <memory>


/**
 * @brief 
 */
class Packet {
public:
	typedef std::size_t Type;
	typedef std::shared_ptr<Packet> Ptr;

	virtual ~Packet();

	virtual Type getType();
};

#endif
