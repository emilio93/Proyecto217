#include<string>
#include<iostream>
#include <set>

//#using namespace std;

//*********************************************************************
//							 Class: Curso
//*********************************************************************

//! Class curso
/*!
 * La clase curso, contiene informacion sobre cada curso
 */
class Curso {

private:

	int id, cupo, grupo, clasesPorPeriodo;//aquí hay un vergo de cosas que no se de donde salen xD
	string nombre, sigla;
public:
	
	
	Profesor profesor; //que quiere hacer aquí juan??
	//!lista periodos de tiempo para el curso
/*! \brief 
 *  \return 
*/
	std::list<Periodo> horario();// devuelve lista de periodos creo que esto no es un método de horario sino de serialization 
	int getCantidadGrupos(*Cursoactual);// me imagino que de alguna manera el método debe sabe de que curso se pregunta
	int getClasesEnSemana(*Cursoactual);// por lo tanto le puede entrar un puntero al curso actual.
};

