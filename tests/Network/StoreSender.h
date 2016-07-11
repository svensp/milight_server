/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 15:07:00 CEST 2016
 */

#ifndef _STORESENDER_H_
#define _STORESENDER_H_

#include "../../src/Network/Sender.h"
#include <string>

/**
 * @brief 
 */
class StoreSender : public Sender {
protected:
	std::string lastSent;
	bool sentCalled;
public:
	StoreSender();
	virtual ~StoreSender();
	virtual void sent(const char *data, size_t bytes);

	bool wasCalled();
	std::string dataSent();
};

#endif
