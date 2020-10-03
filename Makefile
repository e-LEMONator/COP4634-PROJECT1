CXX = c++
CFLAGS = -std=c++11 -Wall -o

main: parse execHandler
	$(CXX) $(CFLAGS) myshell *.cpp 

execHandler: param
	$(CXX) -c $(CFLAGS) execHandler.o execHandler.cpp

parse: param
	$(CXX) -c $(CFLAGS) parse.o parse.cpp

param:
	$(CXX) -c $(CFLAGS) param.o param.cpp

clean:
	$(RM) *.o *.gch core myshell