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
*/	//std::set<Bloque> bloques;//nosotros no seteamos bloques lo traemos de la base de datos ...

    std:: List <Bloque> getBloques(void);// método para traer una lista de los bloques ocupamos que retorne una lista
    static std:: List <Planes> getPlanes(void); //esto era parte de un serialization asi que no se si iría en esta clase	
    
	

};


//*********************************************************************
//							 Class: Serialization
//*********************************************************************

//! Class Serialization
/*!
 * La clase Serialization esta compuesta por bloques
 */
class Serialization {
public:
	std::List <Bloque> getbloques(this);
	

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
	std::set<Curso> cursos;//nosotros treamos la lista de cursos de la base de datos no los ponemos
	List<Cursos> getCursos(void);// ocupamos una lista también
	

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
	int getCantidadGrupos();// me imagino que de alguna manera el método debe sabe de que curso se pregunta
	int getClasesEnSemana();// por lo tanto le puede entrar el curso actual.
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
	int getHorario(void);// esto debe devolver el horario del profe
};


//*********************************************************************
//							 Class: Grupo
//*********************************************************************

//! Class Grupo
/*!
 * La clase grupo contiene información de un grupo de un curso.
 */

class Grupo{

public:
	____ getCurso(___);// no hablamos mucho de que tipo son y que les entra.
             getProfesor();
	     setProfesor();	
	     ponerEnHorario();
	     buscarProfesor();	

}



