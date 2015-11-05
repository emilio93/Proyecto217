CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic -lmysqlcppconn
LFLAGS = -Wall -I/usr/include/cppconn -pedantic
BEFORE = -Wall $(DEBUG) -I/usr/include/cppconn
AFTER = -L/usr/lib -L/usr/include -lmysqlcppconn
TARGET = principal

main: Plan.o BD.o testSerializacion

testBD:
	$(CC)  $(BEFORE) -o bd.exe BD.cpp $(AFTER)

BD.o:
	$(CC) -c $(BEFORE) -o bd.exe BD.cpp $(AFTER)

Plan.o:
	$(CC) -c ../Plan.cpp -o ../Plan.o
testSerializacion:
	$(CC)  $(BEFORE) -o serializacion.exe Serializacion.cpp $(AFTER)

clean :
	rm -f *.o *.exe $(TARGET)

cleanWin :
	del *.o *.exe $(TARGET) 2>nul
