
#Makefile for fenrir
CPPFLAGS += -L /usr/local/lib -I /usr/local/include -L /usr/lib -I /usr/include -D GLM_FORCE_RADIANS
LFLAGS += -std=c++11 -lpthread -lGL -lGLEW -lX11 -lXxf86vm -lXi -lXrandr -lglfw3 -lXcursor
CXX = g++
TARGET = ./bin/fenrir

all:
	$(CXX) $(CPPFLAGS) ./src/*.cpp ./src/graphics/*.cpp $(LFLAGS) -o $(TARGET)
