CPU:=$(shell uname -m)
MODULE:=$(shell basename `pwd`)
ifneq (,$(wildcard main.c))
TARGET:=$(MODULE).$(CPU)
endif
LIBRARY:=lib$(MODULE).a
SOURCES:=$(filter-out main.c,$(wildcard *.c))
OBJECTS:=$(patsubst %.c,%.o,$(SOURCES))

CC:=gcc
RM:=rm -rf

CFLAGS += -I. -Wall -Werror -O2 -g
LFLAGS += -L. -l$(MODULE)

CFLAGS += $(foreach M,$(IMPORTS), -I../$(M))
LFLAGS += $(foreach M,$(IMPORTS), -L../$(M) -l$(M))

%.o: %.c
	$(CC) $(CFLAGS) -c $<


ifneq (,$(wildcard main.c))
all: $(TARGET)

$(TARGET): $(LIBRARY) main.o
	$(CC) main.o -o $(TARGET) $(LFLAGS)

else
all: $(LIBRARY)

endif

$(LIBRARY): $(OBJECTS)
	$(RM) $(LIBRARY)
	$(AR) q $(LIBRARY) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)
	$(RM) $(LIBRARY)

rebuild: clean all

