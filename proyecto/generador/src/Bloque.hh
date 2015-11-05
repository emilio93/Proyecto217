#ifndef CLASE_BLOQUE
#define CLASE_BLOQUE

#include <iostream>
#include <string>

#include "Curso.hh"
#include "Plan.hh"

//*********************************************************************
//							 Class: Bloque
//*********************************************************************

//! Class Bloque
/*!
 * La clase Horario esta compuesta por bloques
 */
class Bloque {

private:

	int id;
	Plan * plan;
	int semestre;
public:

	//!Set de cursos
/*! \brief
 *  \return
*/
	//std::set<Curso> cursos;//nosotros treamos la lista de cursos de la base de datos no los ponemos
	std::list<Curso> * getCursos(void);// ocupamos una lista también

};

#endif
