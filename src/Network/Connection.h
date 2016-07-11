/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 13:36:33 CEST 2016
 */

#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "Receiver.h"
#include "Sender.h"
#include <cstddef>

/**
 * @brief 
 */
class Connection {
public:
	virtual ~Connection();
	virtual void read(Receiver &receiver, size_t bytes) = 0;
	virtual void write(Sender &sender, const char *data, size_t bytes) = 0;
};

#endif
