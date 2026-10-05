CC=g++
CCFLAGS=-c -I.
DEPS=FloatFormatter.hpp
TARGET=float_formatter
OBJS=main.o \
FloatFormatter.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
