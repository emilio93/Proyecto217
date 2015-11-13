#ifndef CLASE_PROFESOR
#define CLASE_PROFESOR

#include <string>
#include <iostream>
#include <set>
#include <queue>

#include "IPeriodo.hh"

class Curso;
class Grupo;


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

//! private int id
/*!
 * Contiene el id asignado al profesor pos la base de datos
 */
	int id; 
	
//! private int horasLaborales
/*!
 * Número constante de horas laborales para el profesor
 */	
	int horasLaborales;


//! private int horasAsignadas
/*!
 * Horas Asignadas de cursos a profesor
 */	
	int horasAsignadas;


//! private string nombre
/*!
 * Nombre del profesor
 */	
	std::string nombre;
	
//! private string nombre
/*!
 * Apellido del profesor
 */	 
	std::string apellido; 
	
	
public:


	std::priority_queue<Curso> * cursos;//No sé si los vamos a usar pero ahi están
	
	//std::priority_queue<IPeriodo> * disponibilidad;
	
	int getHorario(Profesor * Profesoractual);// Esto debe devolver el horario del profe
	
//! Método público bool verificar_curso
/*!
 * Devuelve un 1 si el profesor puede dar el curso
 */	
	bool verificar_curso(Curso * curso_prueba);


//! Método público asignar_grupo
/*!
 * Modifica el horario del profesor y horasAsignadas
 */	
	void asignar_grupo(Grupo * Grupo); /*podria devolver un horario untilizando la función getHorario()*/
	
};

#endif
