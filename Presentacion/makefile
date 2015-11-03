#Esto es un comentario
#Se definen los objetos
OBJS = ProyectoFinal.tex


#Se define el compilador
CC = pdflatex
CC2 = bibtex

#Archivo ejecutable que se va a crear
TARGET = ProyectoFinal.pdf 

#Reglas a ejecutar cuando se ejecute make
all: $(TARGET) 

$(TARGET) : $(OBJS)
	$(CC) $(OBJS)
	$(CC) $(OBJS)
	$(CC) $(OBJS)
	

#Al digitar make clean se borraran todos los archivos compilados
clean:
	rm -f *.log *.aux *.gz *.dvi *.bbl *.blg *.fls
