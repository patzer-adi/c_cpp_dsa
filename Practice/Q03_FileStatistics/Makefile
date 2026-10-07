CC=g++
CCFLAGS=-c -I.
DEPS=FileStats.hpp
TARGET=file_stats
OBJS=main.o \
FileStats.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
