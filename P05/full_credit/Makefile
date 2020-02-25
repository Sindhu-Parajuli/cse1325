CXXFLAGS = --std=c++17

all: Product 

Product: main.o Product.o  Taxfree.o Taxed.o *.h
	$(CXX) $(CXXFLAGS) main.o Product.o Taxfree.o Taxed.o  -o Product


main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
Product.o: Product.cpp *.h
	$(CXX) $(CXXFLAGS) -c Product.cpp -o Product.o
Taxed.o: Taxed.cpp *.h
	$(CXX) $(CXXFLAGS) -c Taxed.cpp -o Taxed.o
Taxfree.o: Taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) -c Taxfree.cpp -o Taxfree.o
Product.gch: Product.h
	$(CXX) $(CXXFLAGS) -c Product.h -o Product.gch
Taxed.gch: Taxed.h
	$(CXX) $(CXXFLAGS) -c Taxed.h -o Taxed.gch
Taxfree.gch: Taxfree.h
	$(CXX) $(CXXFLAGS) -c Taxfree.h -o Taxfree.gch

clean:
	rm -f *.o *.gch ~* a.out Product
        
