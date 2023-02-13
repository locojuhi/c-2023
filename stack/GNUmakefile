CPU:=$(shell uname -m)
TARGET:=$(shell basename `pwd`).$(CPU)
SOURCES:=$(wildcard *.c)
OBJECTS:=$(patsubst %.c,%.o,$(SOURCES))

CC:=gcc
RM:=rm -rf

CFLAGS += -I. -Wall -Werror -O2 -g
LFLAGS +=

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LFLAGS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)

rebuild: clean all


