CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
BEFORE = -Wall $(DEBUG) -I/usr/include/cppconn
AFTER = -L/usr/lib -L/usr/include -lmysqlcppconn

main: BD.o Plan.o testSerializacion

testInstante:
	$(CC) Instante.cpp -o instante.exe $(LFLAGS)
testCurso:
	$(CC) Curso.cpp -o curso.exe $(LFLAGS)
testPlan:
	$(CC) Plan.cpp -o plan.exe $(LFLAGS)
testSerializacion:
	$(CC)  $(BEFORE) -o serializacion.exe BD/Serializacion.cpp Plan.cpp BD/BD.cpp $(AFTER)

Plan.o:
	$(CC) Plan.cpp $(CFLAGS) -o Plan.o
BD.o:
	$(CC) -c $(BEFORE) BD/BD.cpp -o BD.o $(AFTER)
clean :
	rm -f *.o
cleanWin :
	del *.o *.exe 2>nul
