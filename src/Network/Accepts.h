/**
 * Created by cmd-keen
 * on netbook
 * at Fr 24. Jun 20:56:16 CEST 2016
 */

#ifndef _ACCEPTS_H_
#define _ACCEPTS_H_

#include "Connection.h"

/**
 * @brief 
 */
class Accepts {
public:
	virtual ~Accepts();
	virtual void newConnection(Connection &connection) = 0;
};

#endif
