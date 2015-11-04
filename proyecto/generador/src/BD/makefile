CC = g++
OBJS = principal.cpp MiPila.cpp
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic -lmysqlcppconn
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = principal

main:
	$(CC) -Wall -I/usr/include/cppconn -o bd.exe BD.cpp -L/usr/lib -L/usr/include -lmysqlcppconn

testBD:
	$(CC) -Wall -I/usr/include/cppconn -o bd.exe BD.cpp -L/usr/lib -L/usr/include -lmysqlcppconn
	
testSerializacion:
	$(CC) Serializacion.cpp -o serializacion.exe $(DEBUG) $(CFLAGS)
clean :
	rm -f *.o *.exe $(TARGET)
cleanWin :
	del *.o *.exe $(TARGET) 2>nul
