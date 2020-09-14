CXX = c++
CFLAGS = -std=c++11 -Wall -o

main: parse
	$(CXX) $(CFLAGS) myshell *.cpp 

parse:
	$(CXX) -c $(CFLAGS) parse.o parse.cpp

clean:
	$(RM) *.o *.gch core myshell