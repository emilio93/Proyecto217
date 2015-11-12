CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic

#MySQL flags
BEFORE = -Wall -I/usr/include/cppconn
AFTER = -L/usr/lib -L/usr/include -lmysqlcppconn

#Output Directory
ODIR = bin/
SRC = src/
DOXY = doxyfiles/

main: createODIR tests

doxy:
	rm -r docs/
	doxygen
	cp $(DOXY)doxy-boot.js docs/html/doxy-boot.js
createODIR:
	mkdir -p $(ODIR)

tests:
	$(CC) $(BEFORE) $(SRC)tests.cpp -o $(ODIR)tests.exe $(LFLAGS) $(AFTER)

Bloque.o:
	$(CC) $(SRC)Bloque.cpp $(CFLAGS) -o $(ODIR)Bloque.o
Curso.o:
	$(CC) $(SRC)Curso.cpp $(CFLAGS) -o $(ODIR)Curso.o
Grupo.o:
	$(CC) $(SRC)Grupo.cpp $(CFLAGS) -o $(ODIR)Grupo.o
Horario.o:
	$(CC) $(SRC)Horario.cpp $(CFLAGS) -o $(ODIR)Horario.o
Instante.o:
	$(CC) $(SRC)Instante.cpp $(CFLAGS) -o $(ODIR)Instante.o
Periodo.o:
	$(CC) $(SRC)Periodo.cpp $(CFLAGS) -o $(ODIR)Periodo.o
Plan.o:
	$(CC) $(SRC)Plan.cpp $(CFLAGS) -o $(ODIR)Plan.o
Profesor.o:
	$(CC) $(SRC)Profesor.cpp $(CFLAGS) -o $(ODIR)Profesor.o
BD.o:
	$(CC)  -c $(BEFORE) -o $(ODIR)BD.o $(SRC)BD/BD.cpp $(AFTER)
Serializacion.o:
	$(CC) -c $(BEFORE) $(SRC)BD/Serializacion.cpp -o $(ODIR)Serializacion.o $(AFTER)

clean:
	rm -f *.o *.exe
cleanWin :
	del *.o *.exe 2>nul
