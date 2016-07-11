#include_directories(src)
#set(SOURCE
#	main.cpp
	#	MilightServer.cpp
	#	)
#add_subdirectory(milight)

add_library(network
	Connection.cpp
	Connection.h
	DummySender.cpp
	DummySender.h
	Receiver.cpp
	Receiver.h
	Sender.cpp
	Sender.h
	Accepts.h
	Accepts.cpp
	Acceptor.h
	Acceptor.cpp
	PacketWriter/HeaderWriter.h
	PacketWriter/HeaderWriter.cpp
	PacketWriter/PacketSpecificSender.h
	PacketWriter/PacketSpecificSender.cpp
	PacketWriter/PacketWriter.h
	PacketWriter/PacketWriter.cpp
	PacketWriter/SenderFactory.h
	PacketWriter/SenderFactory.cpp
	)
#add_executable(milight_server
#	${SOURCE}
#	)
