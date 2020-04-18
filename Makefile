CC = g++
RM = rm -f
TEST = ./test.sh

CFLAGS = -g -static
OBJS = main.o util.o token.o
TARGET = 9cc

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.hpp.o:

main.o: util.hpp token.hpp
token.o: util.hpp

test: 9cc
	$(TEST)

clean:
	$(RM) $(TARGET) $(OBJS)
