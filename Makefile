###
# Makefile
# Willem van Ketwich
###

CXX = g++
CXXFLAGS = -c -Wall -g -std=c++11
LDFLAGS = -Wall -std=c++11
SRC_DIR = ./source
OBJ_DIR = ./obj
INCLUDES_PATH = ./includes
EXTERNAL_INCLUDES_PATH = $(INCLUDES_PATH)/external

COMMON_SOURCES = $(wildcard $(SRC_DIR)/common/*.cpp)

MAIN_SOURCES = $(wildcard $(SRC_DIR)/main/*.cpp)
TEST_SOURCES = $(wildcard $(SRC_DIR)/test/*.cpp)

OBJ_FILES_COMMON = $(patsubst $(SRC_DIR)/common/%.cpp,$(OBJ_DIR)/%.o,$(COMMON_SOURCES))
OBJ_FILES_MAIN = $(patsubst $(SRC_DIR)/main/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SOURCES))
OBJ_FILES_TEST = $(patsubst $(SRC_DIR)/test/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SOURCES))

COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
EXECUTABLE = pbec
TEST_EXECUTABLE = tests
LIBS = -ldl -lm

.PHONY: all target $(TEST_EXECUTABLE)

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

pbec: $(EXECUTABLE)

tests: $(TEST_EXECUTABLE)

clean:
		find . -name '*.o' -type f -delete; \
		rm pbec tests || true

dockerbuild-ubuntu1604:
		make clean
		docker-compose -f support/docker/docker-compose-ubuntu1604.yml build
		docker-compose -f support/docker/docker-compose-ubuntu1604.yml run ubuntu1604 bash -c "make && ./tests"

dockerbuild-fedora27:
		make clean
		docker-compose -f support/docker/docker-compose-fedora27.yml build
		docker-compose -f support/docker/docker-compose-fedora27.yml run fedora27 bash -c "make && ./tests"

$(EXECUTABLE): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	    $(CXX) $(LDFLAGS) $^ -o $@ -I$(INCLUDES_PATH) -I$(EXTERNAL_INCLUDES_PATH)

$(OBJ_DIR)/%.o:

$(TEST_EXECUTABLE): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	    $(CXX) $(LDFLAGS) $^ -o $@ -I$(INCLUDES_PATH) -I$(EXTERNAL_INCLUDES_PATH)

.cpp.o:
	    $(CXX) $(CXXFLAGS) $< -o $@ -I$(INCLUDES_PATH) -I$(EXTERNAL_INCLUDES_PATH)

