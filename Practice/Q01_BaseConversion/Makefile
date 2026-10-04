CC=g++
CCFLAGS=-c -I.
DEPS=BaseConverter.hpp
TARGET=base_converter
OBJS=main.o \
BaseConverter.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
