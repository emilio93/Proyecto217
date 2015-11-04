#ifndef CLASE_CURSO
#define CLASE_CURSO

#include <string>
#include <list>

#include "IPeriodo.hh"
#include "Grupo.hh"


//#using namespace std;

//*********************************************************************
//							 Class: Curso
//*********************************************************************

//! Class curso
/*!
 * La clase curso, contiene información sobre cada curso.
 */
/**
 * @breif La clase curso representa un curso como se vería en un plan de
 *        estudios, esto es, sin horario, sin profesor, sin número de grupo.
 *        Lo que si tiene es la cantidad de horas del curso en una semana y la
 *        cantidad de clases en la semana, también la sigla y su nombre.
 *        La función es esta clase es concentrar la información de un curso
 *        específico para no delegar esta función a un Grupo.
 *        Un Curso no conoce a sus grupos, puesto que no tiene un fin útil con
 *        estos. Puede entenderse que el plan de estudios, si bien muestra los
 *        cursos, no muestra los grupos, porque estos son ajenos al plan de
 *        estudios, y más bien inherentes al horario que es creado.
 *        Un Curso, sin embargo, si puede crear un Grupo y olvidarse de él.
 *        Difiere esta clase de la conceptualización dada(la del plan de
 *        estudios) porque se contempla la cantidad de grupos que habrán de este
 *        curso.
 *
 * TODO Piensese que en el plan de estudios se puede encontrar a que bloque de
 * 		que plan pertenece el curso, y esto no va a ser un único bloque. Se
 * 		podría tener un método que devuelva una lista de bloques a los cuales el
 * 		curso pertenece. Por ejemplo:
 * 			std::list<Bloque> * bloquesPadre(void);
 */
class Curso {

private:

	//Adecúo los atributos segun el UML

	/**
	 * @breif El id es un identificador único para cada Curso, su valor es
	 *        información irrelevante sobre el Curso.
	 */
	int id;

	/**
	 * @breif La cantidad de horas indica cuantas horas de clases se imparten en
	 *        el curso a lo largo de una semana.
	 */
	int cantidadHoras;

	/**
	 * @breif Las clases en una semana indica la cantidad de clases que se
	 *        imparten del curso a lo largo de una semana.
	 */
	int clasesEnSemana;

	/**
	 * @breif La cantidad de grupos indica cuantos grupos de este curso deben
	 *        existir.
	 */
	int cantidadGrupos;

	/**
	 * @breif El nombre del curso es una manera en que el usuario puede
	 *        identificar el curso.
	 */
	std::string nombre;

	/**
	 * @breif La sigla del curso, al igual que el nombre, le da identidad al
	 *        curso.
	 */
	std::string sigla;

	/* Algunos comentraios
		cupo y grupo, como se había hablado, pertencen a la clase Grupo.

		La representación de un Curso en la base de datos y en el programa es
		diferente, esto porque la base de datos lo único que hace es guardarlos
		a su propia manera. (Perdon, no se como explicar esto)

		id es asignado automaticamente por la base de datos, cada inserción de
			un curso en la tabla Cursos(o como se llame) de la base de datos
			incrementa un contador, eso es el id. Esto sería un problema de
			instanciar nosotros los cursos directamente desde el programa. La
			base de datos ya optimiza y asegura que el id es único, y no
			representa problemas para contar los elementos en la tabla. Esto
			aunque parezca trivial de implementar, se puede volver complicado
			por casos no tomados en cuenta.

		cantidadHoras es asignado a un curso por el usuario y la asignación es
			ajena a nuestro programa, contamos con que esté en la base de datos.

		clasesEnSemana, nombre y sigla les ocurre lo mismo que a cantidadHoras.
	 */

	/*Esto es lo que estaba, lo comento no más

	int id, cupo, grupo, clasesPorPeriodo;//aquí hay un vergo de cosas que no se de donde salen xD
	std::string nombre, sigla;
	*/
public:

	//esto es viejo me parece, va en Grupo
	//Profesor profesor; //que quiere hacer aquí juan??

	//!lista periodos de tiempo para el curso
/*! \brief
 *  \return
*/
	std::list<IPeriodo> horario(void);// devuelve lista de periodos creo que esto no es un método de horario sino de serialization

	/**
	 * @breif Constructor de la clase con sus valores por defecto.
	 * @param id Id El id del curso.
     * @param cantidadHoras La cantidad de horas del curso por semana.
 	 * @param clasesEnSemana La cantidad clases del curso por semana.
	 * @param CantidadGrupos La cantidad de gruposd el curso.
	 * @param nombre Nombre del curso.
	 * @param sigla Sigla del curso.
	 */
	Curso(int id = 0, int cantidadHoras = 0, int clasesEnSemana = 0, int cantidadGrupos = 0, std::string nombre = "", std::string sigla = "");

	/**
	 * @breif Método get para el id del curso.
	 * @return  El id del curso.
	 */
	int getId(void);

	/**
	 * @breif Método set para el id del curso.
	 * @param id El id del curso.
	 */
	void setId(int id);

	/**
	 * @breif Método get para la cantidad de horas del curso por semana.
	 * @return La cantidad de horas del curso por semana.
	 */
	int getCantidadHoras(void);

	/**
	 * @breif Método set para la cantidad de horas del curso por semana.
	 * @param cantidadHoras La cantidad de horas del curso por semana.
	 */
	void setCantidadHoras(int cantidadHoras);

	/**
	 * @breif Método get para las cantidad de clases del curso por semana.
	 * @return  Las clases en una semana del curso.
	 */
	int getClasesEnSemana(void);// por lo tanto le puede entrar un puntero al curso actual.

	/**
	 * @breif Método set para la cantidad clases del curso por semana.
	 * @param clasesEnSemana La cantidad clases del curso por semana.
	 */
	void setClasesEnSemana(int clasesEnSemana);

	/**
	 * @breif Método get para la cantidad de grupos del curso.
	 * @return  La cantidad de grupos del curso
	 */
	int getCantidadGrupos(void);// me imagino que de alguna manera el método debe sabe de que curso se pregunta
								// Se usa this
								// return this->cantidadGrupos
							    // return this->clasesEnSemana

	/**
	 * @breif Método set para la cantidad de grupos del curso.
	 * @param CantidadGrupos La cantidad de gruposd el curso.
	 */
	void setCantidadGrupos(int cantidadGrupos);

	/**
	 * @breif Método get para el nombre del curso.
	 * @return  Nombre del curso.
	 */
	std::string getNombre(void);

	/**
	 * @breif Método set para el nombre del curso.
	 * @param nombre Nombre del curso.
	 */
	void setNombre(std::string nombre);

	/**
	 * @breif Método get para la sigla del curso.
	 * @return  Nombre del curso.
	 */
	std::string getSigla(void);

	/**
	 * @breif Método set para la sigla del curso.
	 * @param sigla Sigla del curso.
	 */
	void setSigla(std::string sigla);

	/**
	 * @breif Este método devuelve un string que representa el curso.
	 * @return  String que representa el curso.
	 */
	std::string toString(void);

	/**
	 * @breif Crea a partir de la información del curso los grupos que
	 *        corresponden al curso. Este método no se encarga ni de elegir un
	 *        horario a los grupos ni de asignar un profesor al grupo, de esto
	 *        se encarga el grupo por si mismo-
	 * @return Una lista de grupos que corresponden al curso.
	 */
	std::list<Grupo*> * crearGrupos(void);

};

#endif
