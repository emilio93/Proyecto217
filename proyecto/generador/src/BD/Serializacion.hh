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

//! Consulta y obtiene resultados de la base de datos, los convierte a objetos
//! utilizados en el sistema.
/**
 * La clase Serializacion se encarga de convertir los resultados de la
 * base de datos en los objetos pertinentes.
 */
class Serializacion {
    private:
        /**
         * @breif Obtiene una conexión con el servidor de la base de datos.
         * @return  La conexión con la base de datos.
         */
        static sql::Connection *getCon(void);

    public:
        /**
         * @breif Obtiene una lista de los planes disponibles en la base de
         * datos.
         */
    	static std::vector<Plan*> *getPlanes(void);

        /**
         * @breif Obtiene los bloques de la base de datos que pertenezcan a un
         *        dado plan.
         */
    	static std::vector<Bloque*> *getBloques(Plan *plan);

        /**
         * @breif Obtiene los cursos de la base de datos que pertenezcan a un
         *        dado bloque.
         */
    	static std::vector<Curso*> *getCursos(Bloque *bloque);
};
#endif
