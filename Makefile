CC=g++
CXXFLAGS=-Wall -g
OBJECTS=main.o model.o tview.o gview.o view.o ai_controller.o
EXECUTABLE=snake
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)

clear:
	$(RM) $(OBJECTS) $(EXECUTABLE)

depend:
	$(CC) -MM $(CXXFLAGS) $(OBJ:.o=.cpp) > .depend

-include .depend
