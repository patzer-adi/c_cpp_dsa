CC=g++
CCFLAGS=-c -I.
DEPS=ConicClassifier.hpp
TARGET=conic_classifier
OBJS=main.o \
ConicClassifier.o
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $(CCFLAGS) $<
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
clean:
	rm -f *.o $(TARGET)
