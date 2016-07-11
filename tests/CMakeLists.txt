add_definitions(-DBOOST_TEST_DYN_LINK)
include_directories(${Boost_INCLUDE_DIRS} ../src)
add_executable(tests
	test.cpp
	Network/TestConnection.cpp
	Network/StoreSender.cpp
	Network/StoreReceiver.cpp
	Network/TestAcceptor.cpp
	Network/TestServer.cpp
	connection.cpp
	acceptor.cpp
	)
target_link_libraries(tests
	${Boost_LIBRARIES}
	network
	boost_unit_test_framework)
