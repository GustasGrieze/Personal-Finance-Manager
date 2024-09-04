CC = g++
CFLAGS = -Wall -std=c++11

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

HDRS = $(wildcard *.h)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) main

rebuild: clean all
