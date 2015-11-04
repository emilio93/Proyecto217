#ifndef CLASE_BLOQUE
#define CLASE_BLOQUE

#include <iostream>
#include <string>

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
	int semestre;
public:

	//!Set de cursos
/*! \brief
 *  \return
*/
	//std::set<Curso> cursos;//nosotros treamos la lista de cursos de la base de datos no los ponemos
	std::list<Cursos> getCursos(void);// ocupamos una lista también

};

#endif
