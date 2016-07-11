/**
 * Created by cmd-keen
 * on netbook
 * at Do 7. Jul 00:34:25 CEST 2016
 */

#ifndef _TESTSERVER_H_
#define _TESTSERVER_H_

#include <Network/Accepts.h>
#include <unordered_map>

/**
 * @brief 
 */
class TestServer : public Accepts {
protected:
	typedef std::unordered_map<Connection *, bool> Connections;
	Connections connections;
public:
	virtual ~TestServer();
	virtual void newConnection(Connection &connection);
	bool wasConnected(Connection &connection);
	unsigned countConnections();
};

#endif
