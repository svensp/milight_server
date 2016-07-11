/**
 * Created by cmd-keen
 * on netbook
 * at Fr 24. Jun 22:11:59 CEST 2016
 */

#ifndef _TESTACCEPTOR_H_
#define _TESTACCEPTOR_H_

#include <Network/Acceptor.h>
#include <unordered_map>

/**
 * @brief 
 */
class TestAcceptor : public Acceptor {
protected:
	typedef std::unordered_map<Accepts *, Accepts *> Servers;
	Servers servers;
public:
	virtual ~TestAcceptor();

	void incomingConnection(Connection &connection);
	virtual void accept(Accepts &accepts);
};

#endif
