#ifndef CLASE_PLAN
#define CLASE_PLAN

#include <string>
#include <iostream>
#include <set>
#include <vector>

class Bloque;


//*********************************************************************
//							 Class: Plan
//*********************************************************************

//! Un plan de estudios.
/*!
 * El plan de estudios designa distintos bloques de cursos, cada bloque
 * representa los cursos sugeridos a llevar en un cierto semestre.
 *
 */
class Plan {
	private:
		//! Identificador del Plan.
		int id;

		//! Nombre del Plan.
		std::string nombre;

	public:
		//! Asigna un Plan.
		/*!
		 * Inicializa los valores del objeto.
		 * @param id Identificador del Plan.
		 * @param nombre Nombre del Plan.
		 */
		Plan(int id, std::string nombre);

		//! Obtiene el id del Plan.
		/*!
		 * Método get del id del Plan.
		 * @return El id del Plan.
		 */
		int getId(void);

		//! Asigna el id del Plan.
		/*!
		 * Método set del id del Plan.
		 * @param id El id del Plan.
		 */
		void setId(int id);

		//! Obtiene el nombre del Plan.
		/*!
		 * Método get del nombre del Plan.
		 * @return El nombre del Plan.
		 */
		std::string getNombre();

		//! Asigna el nombre del Plan.
		/*!
		 * Método set del nombre del Plan.
		 * @param nombre El nombre del Plan.
		 */
		void setNombre(std::string nombre);

		//! Obtiene los planes disponibles.
		/*!
		 * @return Un vector con los planes disponibles.
		 */
	    static std::vector<Plan*> *getPlanes(void); //esto era parte de un serialization

		//! Set de bloques. Obtiene los bloques disponibles del plan.
		/*!
		 *  @return Un vector con los bloques del plan.
		*/
	    std::vector<Bloque*> *getBloques(void);
	// método para traer una lista de los bloques ocupamos que retorne una lista
	//std::set<Bloque> bloques;//nosotros no seteamos bloques lo traemos de la base de datos ...
};
#endif
