#Makefile for fenrir
CPPFLAGS += 
LFLAGS +=
CXX = g++
TARGET = ./bin/fenrir

all:
	$(CXX) $(CPPFLAGS) ./src/* $(LFLAGS) -o $(TARGET)
