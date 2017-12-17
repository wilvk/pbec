CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)
SRCM= ./basic_tests.cpp
OBJM = $(SRCM:.cpp=.o)
LINKFLAGS= -lcppunit
 
test: basic_tests.cpp $(OBJM)
	$(CXX) $(CXXFLAGS) -o $@ basic_tests.cpp $(OBJM) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)
 
# Default compile
 
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

