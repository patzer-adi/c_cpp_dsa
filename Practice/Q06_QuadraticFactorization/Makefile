CC=g++
CCFLAGS=-c -I.
DEPS=QuadraticFactorizer.hpp
TARGET=quad_factor
OBJS=main.o \
QuadraticFactorizer.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
