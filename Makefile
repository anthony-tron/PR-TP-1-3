client: socketUtils.o
	g++ -o client -Wall socketUtils.o client.cpp

socketUtils.o: socketUtils.h socketUtils.cpp
	g++ -c socketUtils.cpp

