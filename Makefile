CXXFLAGS = -Wall -g    # Opções do compilador: todos warnings e debug info

PROG = MyRobot
FONTES = Sensor.cpp Ultra.cpp Servos.cpp
OBJETOS = $(FONTES:.cpp=.o)

$(PROG): $(OBJETOS)
	g++ $(CXXFLAGS) $(OBJETOS) -o $@

clean:
	-@ rm -f $(OBJETOS) $(PROG)

depend:
	makedepend -- ${CXXFLAGS} -- ${FONTES}

