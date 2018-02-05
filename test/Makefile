CXX = g++
CXXFLAGS = -g -L/usr/src/gtest -Wall -std=c++11
CXXLIBFLAGS = -lgtest -lpthread
INCS = -I/usr/include
OBJS = ../src/dicegame.o ../src/Player.o testDiceGame.o testPlayer.o

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCS) -o testAll  diceGameTestAll.cpp $(OBJS) $(CXXLIBFLAGS)

.cpp.o:
		$(CXX) $(CXXFLAGS) $(CXXLIBFLAGS) -c $< -o $@ $(INCS)

clean:
		rm testAll *.o ../src/*.o
