CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# Object files needed
OBJECTS := llrec-test.o llrec.o

all: llrec-test

# Target to build llrec-test executable
llrec-test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Target to compile llrec-test object file
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to compile llrec object file (if you have a separate implementation file)
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o llrec-test *~

.PHONY: clean all
