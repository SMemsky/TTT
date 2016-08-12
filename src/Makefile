#Makefile for Tick-tack-toe

Target = game
TargetPath = ../build/bin/

CXX = g++
CXXFLAGS = -O0 -g -Wall -std=c++14 -I./
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window

MAIN_OBJECTS = main.o \
	Game.o \
	Graphics.o \
	Engine.o

all: game

game: $(MAIN_OBJECTS)
	$(CXX) $(MAIN_OBJECTS) -o $(TargetPath)$(Target) $(LDFLAGS)

main.o: main.cpp \
		Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.h \
		Graphics.h \
		Engine.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Graphics.o: Graphics.cpp Graphics.h
	$(CXX) $(CXXFLAGS) -c Graphics.cpp

Engine.o: Engine.cpp Engine.h
	$(CXX) $(CXXFLAGS) -c Engine.cpp

clean:
	rm -r *.o

.PHONY: all game clean
