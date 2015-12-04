CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = bb7k
OBJECTS = controller.o game.o gym.o player.o propertytile.o randomgenerator.o residence.o tile.o view.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
