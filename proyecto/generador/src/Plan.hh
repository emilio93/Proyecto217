#ifndef CLASE_PLAN
#define CLASE_PLAN

#include <string>
#include <iostream>
#include <set>
#include <vector>

#include "Bloque.hh"
//#using namespace std;

//*********************************************************************
//							 Class: Plan
//*********************************************************************

//! Class Plan
/*!l
 * Esta clase final, salida del flujo
 */
class Plan {

private:

	int id;
	std::string nombre;

public:
	Plan(int id, std::string nombre);

	int getId(void);

	void setId(int id);

	std::string getNombre();

	void setNombre(std::string nombre);

	//!Set de bloques
/*! \brief
 *  \return
*/	//std::set<Bloque> bloques;//nosotros no seteamos bloques lo traemos de la base de datos ...
    static std::vector<Plan*> * getPlanes(void); //esto era parte de un serialization
    std::vector<Bloque*> * getBloques(Plan * PlanActual);// método para traer una lista de los bloques ocupamos que retorne una lista


};

#endif
