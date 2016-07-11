/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 13:53:40 CEST 2016
 */

#ifndef _SENDER_H_
#define _SENDER_H_

#include <cstddef>
#include <memory>

/**
 * @brief 
 */
class Sender {
public:
	typedef std::unique_ptr<Sender> SenderPtr;
	virtual ~Sender();
	virtual void sent(const char *data, size_t bytes) = 0;
};

#endif
