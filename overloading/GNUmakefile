CPU:=$(shell uname -m)
TARGET:=$(shell basename `pwd`).$(CPU)
SOURCES:=$(wildcard *.cpp)
OBJECTS:=$(patsubst %.cpp,%.o,$(SOURCES))

CXX:=g++
RM:=rm -rf

CFLAGS += -std=c++17 -Wall -Werror -O2 -g
LFLAGS +=

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LFLAGS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

rebuild: clean all


