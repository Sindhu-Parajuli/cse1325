CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all:mainwin

mainwin: main.o mainwin.o customer.o store.o options.o desktop.o order.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o customer.o store.o options.o desktop.o order.o entrydialog.o $(GTKFLAGS) -o store

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

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