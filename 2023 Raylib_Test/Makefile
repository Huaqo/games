# Original command: g++ src/*.cpp -std=c++17 -Iinclude -Llib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o bin/build_osx && ./bin/build_osx

# Variables
CC = g++
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
HDRS = $(wildcard include/*.h)
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LIBS = lib/libraylib.a
OUTFILE = bin/build_osx
FLAGS = -std=c++17

# Default command
all: build

# Compile
build: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(FRAMEWORKS) $(LIBS) -o $(OUTFILE)

# Run
run: 
	./$(OUTFILE)

# Cleanup
clean:
	rm -f $(OBJS) $(OUTFILE)

%.o: %.cpp $(HDRS)
	$(CC) -c $< -o $@ $(FLAGS) $(INCLUDE_PATHS)


.PHONY: all build run clean