CC = gcc
CFLAGS = -I/opt/homebrew/opt/glew/include -I/opt/homebrew/opt/glfw/include
LDFLAGS = -L/opt/homebrew/opt/glew/lib -L/opt/homebrew/opt/glfw/lib -lGLEW -lglfw -framework OpenGL
TARGET = main

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -f $(TARGET)
