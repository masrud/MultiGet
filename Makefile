CC=g++
CFLAGS=-c -I ./curl/include
LDFLAGS=-lcurl

all: MultiGet

MultiGet: MultiGet.o utility.o
	$(CC) -o $@ $^ $(LDFLAGS)
MultiGet.o: MultiGet.cc utility.cc
	$(CC) $(CFLAGS) $^

.PHONY: clean cleanest

clean:
	rm *.o
	rm MultiGet
