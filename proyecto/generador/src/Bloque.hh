#include<string>
#include<iostream>
#include <set>

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
public:
	
	//!Set de cursos
/*! \brief 
 *  \return 
*/
	//std::set<Curso> cursos;//nosotros treamos la lista de cursos de la base de datos no los ponemos
	List <Cursos> getCursos(void);// ocupamos una lista también
	

};
