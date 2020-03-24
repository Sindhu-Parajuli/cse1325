CXXFLAGS = --std=c++17



store: main.o customer.o store.o options.o desktop.o order.o *.h
	$(CXX) $(CXXFLAGS) main.o customer.o store.o options.o desktop.o order.o -o store

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o
desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o


clean:
	rm -f *.o *.gch a.out store
