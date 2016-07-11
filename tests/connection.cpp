/**
 * Created by cmd-keen
 * on netbook
 * at So 12. Jun 14:39:11 CEST 2016
 */

#include <boost/test/unit_test.hpp>
#include "Network/TestConnection.h"
#include "Network/StoreSender.h"
#include "Network/StoreReceiver.h"
#include <string>
#include <iostream>
using namespace std;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(global);

BOOST_AUTO_TEST_CASE(checkStoreSender) {
	StoreSender sender;

	string data = "abcdefghij";
	sender.sent(data.data(), data.length());

	BOOST_CHECK( sender.wasCalled() );
	BOOST_CHECK( sender.dataSent() == data );
}

BOOST_AUTO_TEST_CASE(checkSend) {

	TestConnection sendConnection, receiveConnection;
	sendConnection.pair( receiveConnection );
	receiveConnection.pair( sendConnection );

	string data = "abcdefghij";

	StoreSender sender;
	//receiveConnection.read( , data.length() );
	sendConnection.write( sender, data.data(), data.length() );
	BOOST_CHECK( sender.wasCalled() );
	BOOST_CHECK( sender.dataSent() == data );
}

BOOST_AUTO_TEST_CASE(checkReceivedAfter) {

	TestConnection sendConnection, receiveConnection;
	sendConnection.pair( receiveConnection );
	receiveConnection.pair( sendConnection );

	string data = "abcdefghij";

	StoreSender sender;
	StoreReceiver receiver;

	sendConnection.write( sender, data.data(), data.length() );
	BOOST_CHECK( sender.wasCalled() );
	BOOST_CHECK_EQUAL( sender.dataSent(), data );

	receiveConnection.read( receiver, data.length() );
	BOOST_CHECK( receiver.getDataReceived() == data );
	BOOST_CHECK( receiver.getSizeReceived() == data.length() );
}

BOOST_AUTO_TEST_CASE(checkReceivedBefore) {

	TestConnection sendConnection, receiveConnection;
	sendConnection.pair( receiveConnection );
	receiveConnection.pair( sendConnection );

	string data = "abcdefghij";
	string firstPart = "abc";
	string secondPart = "defghij";

	StoreSender sender;
	StoreReceiver receiver;

	receiveConnection.read( receiver, data.length() );
	sendConnection.write( sender, data.data(), 3 );
	BOOST_CHECK( sender.wasCalled() );
	BOOST_CHECK_EQUAL( sender.dataSent(), firstPart );

	BOOST_CHECK_EQUAL( receiver.isCalled(), false );
}

BOOST_AUTO_TEST_CASE( receiveMultipleTimes ) {

	TestConnection sendConnection, receiveConnection;
	sendConnection.pair( receiveConnection );
	receiveConnection.pair( sendConnection );

	StoreSender sender;
	StoreReceiver receiver;

	string data = "abcdefghijklmnopqrstuvwxyz";
	for(unsigned index = 0 ; (index+1) * 4 < data.length() ; ++index) {
		receiveConnection.read(receiver, 4);
	}

	unsigned writtenBytes = 0;
	for(unsigned index = 0 ; (index+1) * 3 < data.length() ; ++index) {
		sendConnection.write( sender, data.substr(index * 3, 3).data(), 3);

		writtenBytes += 3;
		if(writtenBytes >= 4) {

			BOOST_CHECK_EQUAL( receiver.isCalled(), true );
			writtenBytes -= 4;
			receiver.resetCalled();

		} else {
			BOOST_CHECK_EQUAL( receiver.isCalled(), false );
		}
	}
}

BOOST_AUTO_TEST_SUITE_END();
