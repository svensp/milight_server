/**
 * Created by cmd-keen
 * on netbook
 * at Do 7. Jul 00:36:38 CEST 2016
 */

#include "TestServer.h"

TestServer::~TestServer() {
}

void TestServer::newConnection(Connection &connection) {
	connections[&connection] = true;
}


bool TestServer::wasConnected(Connection &connection) {
	auto i = connections.find( &connection );

	if( i == connections.end() )
		return false;

	if ( i->second == false )
		return false;

	return true;
}

unsigned TestServer::countConnections() {
	unsigned count = 0;

	for(auto i = connections.begin() ; i != connections.end() ; ++i ) {
		if(i->second == false)
			continue;

		++count;
	}

	return count;
}

