/**
 * Created by cmd-keen
 * on netbook
 * at Fr 24. Jun 20:53:24 CEST 2016
 */

#include <boost/test/unit_test.hpp>
#include "Network/TestAcceptor.h"
#include "Network/TestServer.h"
#include "Network/TestConnection.h"

BOOST_AUTO_TEST_SUITE(global);

BOOST_AUTO_TEST_CASE( connect ) {
	TestServer testServer;
	TestAcceptor testAcceptor;
	TestConnection connection;

	testAcceptor.accept( testServer );
	testAcceptor.incomingConnection(connection);

	BOOST_CHECK_EQUAL( testServer.countConnections(), 1 );
	BOOST_CHECK_EQUAL( testServer.wasConnected(connection), true );
}

BOOST_AUTO_TEST_SUITE_END();
