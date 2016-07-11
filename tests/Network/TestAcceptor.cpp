/**
 * Created by cmd-keen
 * on netbook
 * at Fr 24. Jun 22:12:31 CEST 2016
 */

#include "TestAcceptor.h"

TestAcceptor::~TestAcceptor() {
}

void TestAcceptor::incomingConnection(Connection & connection) {

	for(auto i = servers.begin() ; i != servers.end() ; ++i ) {
		i->second->newConnection(connection);
	}
}

void TestAcceptor::accept(Accepts & accepts) {
	servers[&accepts] = &accepts;
}

