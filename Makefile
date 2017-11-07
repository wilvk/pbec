###
# Makefile
# Willem van Ketwich
###

CXX = g++
CXXFLAGS = -Wall -O3 -std=c++11
LDFLAGS = -Wall -O3 -std=c++11
SRC_DIR = ./
OBJ_DIR = ./
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
INCDIRS = --I ./
LIBDIRS =
LIBS = -ldl -lm

.PHONY: all clean

all: pbl

pbl: $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $(LIBDIRS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o *.d pbl

CXXFLAGS += -MMD
-include $(OBJ_FILES:.o=.d)
