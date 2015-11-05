#ifndef CLASE_PROFESOR
#define CLASE_PROFESOR

#include <string>
#include <iostream>
#include <set>
#include <queue>

#include "IPeriodo.hh"

class Curso;


//#using namespace std;

//*********************************************************************
//							 Class: Profesor
//*********************************************************************

//! Class Profesor
/*!
 * La clase profesor, contiene informacion sobre cada profesor de la escuela
 */
class Profesor {

private:

	int id, horasLaborales, horasAsignadas;
	std::string nombre, apellido; //esto no se porque está aquí xD que buscaban con esto?
public:


	std::priority_queue<Curso> * cursos;//no se si los vamos a usar pero ahi están
	//std::priority_queue<IPeriodo> * disponibilidad;
	int getHorario(Profesor * Profesoractual);// esto debe devolver el horario del profe
};

#endif
