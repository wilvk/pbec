###
# Makefile
# Willem van Ketwich
###

CC = g++
CFLAGS = -c -Wall -g -std=c++11 -v
LDFLAGS = -Wall -std=c++11 -v
COMMON_SOURCES = buffer.cpp pbemain.cpp
TARGET_SOURCES = main.cpp
TEST_SOURCES = test_main.cpp
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
	TARGET_OBJECTS = $(TARGET_SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
	EXECUTABLE = pbel
	TEST_EXECUTABLE = tests
LIBS = -ldl -lm

.PHONY: all target tests

all: pbel tests

pbel: $(EXECUTABLE)

tests: $(TEST_EXECUTABLE)

clean:
	    rm -f *.o *.d pbel tests

$(EXECUTABLE): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	    $(CC) $(LDFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	    $(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	    $(CC) $(CFLAGS) $< -o $@
