#Makefile for Tick-tack-toe

Target = game
TargetPath = ../build/bin/

CXX = g++
CXXFLAGS = -O0 -g -Wall -std=c++14
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window -lGL -lpthread

MAIN_OBJECTS = main.o \
	Game.o \
	GameBoard.o \
	Graphics.o \
	Engine.o \
	Interface.o \
	Widget.o

all: game

game: $(MAIN_OBJECTS)
	$(CXX) $(MAIN_OBJECTS) -o $(TargetPath)$(Target) $(LDFLAGS)

main.o: main.cpp \
		Game.h \
		Engine.h \
		GameBoard.h \
		EMarker.h \
		Graphics.h \
		Interface.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.h \
		Engine.h \
		GameBoard.h \
		EMarker.h \
		Graphics.h \
		Interface.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

GameBoard.o: GameBoard.cpp GameBoard.h \
		EMarker.h
	$(CXX) $(CXXFLAGS) -c GameBoard.cpp

Graphics.o: Graphics.cpp Graphics.h
	$(CXX) $(CXXFLAGS) -c Graphics.cpp

Engine.o: Engine.cpp Engine.h \
		GameBoard.h \
		EMarker.h
	$(CXX) $(CXXFLAGS) -c Engine.cpp

Interface.o: Interface.cpp Interface.h \
		Game.h \
		Widget.h
	$(CXX) $(CXXFLAGS) -c Interface.cpp

Widget.o: Widget.cpp Widget.h
	$(CXX) $(CXXFLAGS) -c Widget.cpp

clean:
	rm -r *.o

.PHONY: all game clean
