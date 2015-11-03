CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = principal

#$(TARGET) : $(OBJS)
#	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
#
main:
	$(CC) Instante.cpp
BD.o:
	$(CC) $(CFLAGS) BD/BD.cpp
Serializacion.o:
	$(CC) $(CFLAGS) BD/Serializacion.cpp
clean :
	rm -f *.o $(TARGET)
cleanWin :
	del *.o *.exe $(TARGET) 2>nul
