#include<string>
#include<iostream>
#includes<set>

#using namespace std;

//*********************************************************************
//							 Class: Plan
//*********************************************************************

//! Class Plan
/*!l
 * Esta clase final, salida del flujo
 */
class Plan {
public:
	//!Set de bloques
/*! \brief 
 *  \return 
*/
	std::set<Bloque> bloques;


};



//*********************************************************************
//							 Class: Bloque
//*********************************************************************

//! Class Bloque
/*!
 * La clase Horario esta compuesta por bloques
 */
class Bloque {
public:
	int semestre;
	//!Set de cursos
/*! \brief 
 *  \return 
*/
	std::set<Curso> cursos;


};

//*********************************************************************
//							 Class: Horario
//*********************************************************************

//! Class Horario
/*!
 * La clase Horario ???
 */
class Horario {
public:
	//!Set de cursos
/*! \brief 
 *  \return 
*/
	std::multiset<Curso> cursos;


};


//*********************************************************************
//							 Class: Curso
//*********************************************************************

//! Class curso
/*!
 * La clase curso, contiene informacion sobre cada curso
 */
class Curso {
public:
	int id, cupo, grupo, clasesPorPeriodo;
	string nombre, sigla;
	Profesor profesor; 
	//!lista periodos de tiempo para el curso
/*! \brief 
 *  \return 
*/
	std::list<Periodo> horario;

};

//*********************************************************************
//							 Class: Profesor
//*********************************************************************

//! Class Profesor
/*!
 * La clase profesor, contiene informacion sobre cada profesor de la escuela
 */
class Profesor {
public:
	int id, horasLaborales, horasAsignadas;
	string nombre, apellido; 
	std::PriorityQueue<Curso> cursos;
	std::PriorityQueue<IPeriodo> disponibilidad;
};
