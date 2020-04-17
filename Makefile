CC = g++
RM = rm -f
TEST = ./test.sh

CFLAGS = -g -static
OBJS = main.o
TARGET = 9cc

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -c $<

test: 9cc
	$(TEST)

clean:
	$(RM) $(OBJS)
