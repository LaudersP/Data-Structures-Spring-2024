CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = ../../src
INCLUDE_DIR = ../../include
BIN_DIR = ../../bin/linux
TEMP_DIR = ../../temp/linux
TARGET = $(BIN_DIR)/Application.exe

SRCS = $(SRC_DIR)/Application.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(TEMP_DIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEMP_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCLUDE_DIR)

clean:
	rm -f $(OBJS) $(TARGET)
