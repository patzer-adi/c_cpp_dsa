CC=g++
CCFLAGS=-c -I.
DEPS=FractionReducer.hpp
TARGET=fraction_reducer
OBJS=main.o \
FractionReducer.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
