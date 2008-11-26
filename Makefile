# DO NOT DELETE
OBJS = word_search.o puzzle.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -O2 $(DEBUG)
LFLAGS = -Wall -O2 $(DEBUG)

wordsearch : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o wordsearch

puzzle.o : puzzle.h
	$(CC) $(CFLAGS) puzzle.cpp

word_search.o : puzzle.cpp puzzle.h
	$(CC) $(CFLAGS) word_search.cpp

clean:
	\rm *.o wordsearch