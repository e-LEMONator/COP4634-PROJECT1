CXX = c++
CFLAGS = -std=c++11 -Wall 

main: parse execHandler
	$(CXX) $(CFLAGS) -o myshell.exe *.cpp 

execHandler: param
	$(CXX) -c $(CFLAGS) -o execHandler.o execHandler.cpp

parse: param
	$(CXX) -c $(CFLAGS) -o parse.o parse.cpp

param:
	$(CXX) -c $(CFLAGS) -o param.o param.cpp

clean:
	$(RM) *.o *.gch core myshell *.exe

debug: CFLAGS += -D DEBUG
debug: main