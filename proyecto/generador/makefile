CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic

#Output Directory
ODIR = ../bin/

BEFORE = -Wall $(DEBUG) -I/usr/include/cppconn
AFTER = -L/usr/lib -L/usr/include -lmysqlcppconn


main: createODIR tests

createODIR:
	mkdir -p $(ODIR)

tests:
	$(CC) $(BEFORE) tests.cpp -o $(ODIR)tests.exe $(LFLAGS) $(AFTER)

Bloque.o:
	$(CC) Bloque.cpp $(CFLAGS) -o $(ODIR)Bloque.o
Curso.o:
	$(CC) Curso.cpp $(CFLAGS) -o $(ODIR)Curso.o
Grupo.o:
	$(CC) Grupo.cpp $(CFLAGS) -o $(ODIR)Grupo.o
Horario.o:
	$(CC) Horario.cpp $(CFLAGS) -o $(ODIR)Horario.o
Instante.o:
	$(CC) Instante.cpp $(CFLAGS) -o $(ODIR)Instante.o
Periodo.o:
	$(CC) Periodo.cpp $(CFLAGS) -o $(ODIR)Periodo.o
Plan.o:
	$(CC) Plan.cpp $(CFLAGS) -o $(ODIR)Plan.o
Profesor.o:
	$(CC) Profesor.cpp $(CFLAGS) -o $(ODIR)Profesor.o
BD.o:
	$(CC)  -c $(BEFORE) -o $(ODIR)BD.o BD/BD.cpp $(AFTER)
Serializacion.o:
	$(CC) -c $(BEFORE) BD/Serializacion.cpp -o $(ODIR)Serializacion.o $(AFTER)
	
clean:
	rm -f *.o
cleanWin :
	del *.o *.exe 2>nul
