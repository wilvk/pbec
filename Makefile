###
# Makefile
# Willem van Ketwich
###

CXX = g++
CXXFLAGS = -Wall -O3 -std=c++11
LDFLAGS = -Wall -O3 -std=c++11 -v
SRC_DIR = ./
OBJ_DIR = ./
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
INCDIRS = --I ./
LIBDIRS =
LIBS = -ldl -lm

.PHONY: all clean

all: pbel

pbel: $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.d pbl

test:
	$(MAKE) clean && $(MAKE) && cd tests && $(MAKE) clean && $(MAKE) && ./tests

CXXFLAGS += -MMD
-include $(OBJ_FILES:.o=.d)
