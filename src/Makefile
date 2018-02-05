CXX = g++
CXXFLAGS = -g -Wall
OBJS = dicegame.o

diceGame: application.cpp $(OBJS)
		$(CXX) $(CXXFLAGS) -o diceGame application.cpp $(OBJS)

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
		rm *.o diceGame
