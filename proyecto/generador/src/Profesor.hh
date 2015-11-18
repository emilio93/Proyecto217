#ifndef CLASE_PROFESOR
#define CLASE_PROFESOR

#include <string>
#include <iostream>
#include <set>
#include <queue>

#include "IPeriodo.hh"

class Curso;
class Grupo;

//*********************************************************************
//							 Class: Profesor
//*********************************************************************

//! Un profesor. Conoce sus grupos así como sus horario.
/*!
 * Un profesor maneja su tiempo, de esta manera puede aceptar o declinar cursos
 * que le son asignados según su horario y sus horas laborales. De la misma
 * manera está al tanto de que grupos le han sido asignados.
 */
class Profesor {
	private:

		//! El identificador único del profesor.
		/*!
		 * Contiene el id asignado al profesor en la base de datos
		 */
		int id;

		//! Cantidad máxima de horas que puede trabajar el profesor.
		/*!
		 * Número constante de horas laborales para el profesor.
		 */
		int horasLaborales;

		//! Horas Asignadas de cursos a profesor.
		/*!
		 * Es la cantidad de horas que le han sido asignadas al profesor.
		 * Esta cantidad no debe sobrepasar la cantidad de horas laborales del
		 * profesor.
		 */
		int horasAsignadas;

		//! Nombre del profesor.
		/*!
		 * Nombre del profesor.
		 */
		std::string nombre;

		//! Apellido del profesor.
		/*!
		 * Apellido del profesor.
		 */
		std::string apellido;

		//! Los cursos que el profesor puede impartir.
		/*!
		 *  Son cursos que el profesor tiene la capacidad de impartir.
		 */
		std::vector<Curso*> *cursosDados;

	public:
		int getHorario(Profesor *Profesoractual);// Esto debe devolver el horario del profe

		//! Verifica si el profesor da cierto curso.
		/*!
		 * Devuelve un 1 si el profesor puede dar el curso
		 * @param cursoPrueba El curso que el profesor chequea si puede dar.
		 */
		bool verificarCurso(Curso *cursoPrueba);


		//! El profesor se asigna un grupo
		/*!
		 * Modifica el horario del profesor y horasAsignadas
		 * @param grupo El grupo que se asigna el profesor.
		 */
		void asignarGrupo(Grupo *grupo); /*podria devolver un horario untilizando la función getHorario()*/
};
#endif
