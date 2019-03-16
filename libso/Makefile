.SUFFIXES: .cpp .cxx .o
TARGET = libanti-collision.so
OBJS=anti-collision.o
LIBS = -lm
LIB_DIR = -L. -L/usr/lib64/
INC_DIR = -I. -I/usr/include/
CC = g++ -fPIC -g
MKSO = g++ -g -shared

all: lib

lib: $(OBJS)
	$(MKSO) -o $(TARGET) $(OBJS) $(LIB_DIR) $(LIBS)

.cxx.o:
	$(CC)  -c $(INC_DIR) -o $@ $<

clean:
	rm -f *.o $(TARGET)

.PHONY: clean
