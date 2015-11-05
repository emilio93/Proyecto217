#ifndef CLASE_SERIALIZACION
#define CLASE_SERIALIZACION

#include <string>
#include <vector>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "BD.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"

/**
 * @breif La clase Serializacion se encarga de convertir los resultados de la
 *        base de datos en los objetos pertinentes.
 */
class Serializacion {
    private:
        static sql::Connection * getCon(void);
    public:
    	static std::vector<Plan*> * getPlanes(void);
    	static std::vector<Bloque*> * getBloques(Plan * plan);
    	static std::vector<Curso*> * getCursos(Bloque * bloque);

};

#endif
