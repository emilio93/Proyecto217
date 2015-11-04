#ifndef CLASE_PLAN
#define CLASE_PLAN

#include<string>
#include<iostream>
#include <set>

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

public:

	//!Set de bloques
/*! \brief
 *  \return
*/	//std::set<Bloque> bloques;//nosotros no seteamos bloques lo traemos de la base de datos ...
    static List <Planes> getPlanes(void); //esto era parte de un serialization
    List <Bloque> getBloques(*PlanActual);// método para traer una lista de los bloques ocupamos que retorne una lista

};

#endif
