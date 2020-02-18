CXXFLAGS = --std=c++17

all: coin

color: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
color.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
color.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch
test.o:test.cpp*.h
        $(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch ~* a.out coin

