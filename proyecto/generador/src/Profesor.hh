#include<string>
#include<iostream>
#include <set>

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
	string nombre, apellido; //esto no se porque está aquí xD que buscaban con esto?
public:
	
	
	std::PriorityQueue<Curso> cursos;//no se si los vamos a usar pero ahi están
	std::PriorityQueue<IPeriodo> disponibilidad;
	int getHorario(*Profesoractual);// esto debe devolver el horario del profe
};
