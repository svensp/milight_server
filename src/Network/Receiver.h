/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 13:49:39 CEST 2016
 */

#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <cstddef>

/**
 * @brief 
 */
class Receiver {
public:
	virtual ~Receiver();
	virtual void receive(const char *data, size_t size) = 0;
};

#endif
