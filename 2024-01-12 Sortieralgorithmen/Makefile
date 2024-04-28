CC = em++
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, bin/%.o, $(SRCS))
HDRS = $(wildcard include/*.h)
INCLUDE_PATHS = -Iinclude -I. -I C:/raylib/raylib/src -I C:/raylib/raylib/src/external
LIBRARY_PATHS = -Llib -L. -L C:/raylib/raylib/src
LIBS = -lraylib
OUTFILE = index.html
FLAGS = -Wall -std=c++20 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' -s EXPORTED_RUNTIME_METHODS=ccall -DPLATFORM_WEB --shell-file shell.html

bin/%.o: src/%.cpp $(HDRS)
	$(CC) -c $< -o $@ $(FLAGS) $(INCLUDE_PATHS)

build: $(OBJS)
	$(CC) $(OBJS) -o $(OUTFILE) $(FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LIBS)

.PHONY: all build run clean
