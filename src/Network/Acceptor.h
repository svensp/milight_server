/**
 * Created by cmd-keen
 * on netbook
 * at Fr 24. Jun 20:56:06 CEST 2016
 */

#ifndef _ACCEPTOR_H_
#define _ACCEPTOR_H_

#include "Accepts.h"

/**
 * @brief 
 */
class Acceptor {
public:
	virtual ~Acceptor();
	virtual void accept(Accepts &accepts) = 0;
};

#endif
