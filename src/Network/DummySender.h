/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 14:51:08 CEST 2016
 */

#ifndef _DUMMYSENDER_H_
#define _DUMMYSENDER_H_

#include "Sender.h"

/**
 * @brief 
 */
class DummySender : public Sender {
public:
	virtual ~DummySender();
	virtual void sent(const char *data, size_t bytes);
};

#endif
