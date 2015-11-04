#include<string>
#include<iostream>
#include <set>

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
	int horario;
	int cantidadhoras;
	
public:
	    int getCurso(*GrupoActual);// devuelve un puntero al curso de este grupo.
            std::List <Profesores > getProfesor(*CursoActual);// devuelve una lista de profesores disponibles Emilio dijo que se podia implementar en 
	   					 //SQL la parte de pedir profes disponibles pero sino ahi se hace en el método.
	    void setProfesor(*Profesorasignado);	
	    void ponerEnHorario(*GrupoActual);
	    int buscarProfesor(&List<Profesores>);//Creo que este busca un profesor de la lista disponible que pueda ser usado para el grupo.

}
