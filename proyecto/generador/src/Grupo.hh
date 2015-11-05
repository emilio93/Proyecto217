#ifndef CLASE_GRUPO
#define CLASE_GRUPO

#include <string>
#include <iostream>
#include <set>
#include <vector>

#include "Curso.hh"
#include "Profesor.hh"
#include "IPeriodo.hh"

//#using namespace std;
//*********************************************************************
//							 Class: Grupo
//*********************************************************************

//! Class Grupo
/*!
 * La clase grupo contiene información de un grupo de un curso.
 */

class Grupo{
private:
	int id;
	Curso * curso;
	Profesor * profesor;
	std::vector<IPeriodo*> * horario;
	//int horario;
	int cantidadhoras;

public:
	    Curso * getCurso(Grupo * GrupoActual);// devuelve un puntero al curso de este grupo.
        std::list <Profesor> getProfesor(Curso * CursoActual);// devuelve una lista de profesores disponibles Emilio dijo que se podia implementar en
	   					 //SQL la parte de pedir profes disponibles pero sino ahi se hace en el método.
	    void setProfesor(Profesor * Profesorasignado);
	    void ponerEnHorario(Grupo * GrupoActual);
	    //int buscarProfesor(&List<Profesores>);//Creo que este busca un profesor de la lista disponible que pueda ser usado para el grupo.

};

#endif
