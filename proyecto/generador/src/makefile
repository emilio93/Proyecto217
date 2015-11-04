CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = principal

main:
	$(CC) Curso.cpp -o curso $(DEBUG) $(CFLAGS)
	
testInstante:
	$(CC) Instante.cpp -o instante $(DEBUG) $(CFLAGS)
testCurso:
	$(CC) Curso.cpp -o curso $(DEBUG) $(CFLAGS)
testBD:
	$(CC) $(CFLAGS) BD/BD.cpp -o bd $(DEBUG) $(CFLAGS)
testSerializacion:
	$(CC) $(CFLAGS) BD/Serializacion.cpp -o serializacion $(DEBUG) $(CFLAGS)
clean :
	rm -f *.o $(TARGET)
cleanWin :
	del *.o *.exe $(TARGET) 2>nul
