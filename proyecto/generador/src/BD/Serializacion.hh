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

//! Consulta y obtiene resultados de la base de datos, los convierte a objetos utilizados en el sistema.
/*!
 * La clase Serializacion se encarga de convertir los resultados de la
 * base de datos en los objetos pertinentes.
 */
class Serializacion {
    private:
        //! Obtiene una conexión con la base de datos.
        /*!
         * Obtiene una conexión con el servidor de la base de datos.
         * @return  La conexión con la base de datos.
         */
        static sql::Connection *getCon(void);

    public:
        //! Obtiene los planes existentes en la base de datos.
        /*!
         * Obtiene una lista de los planes disponibles en la base de
         * datos.
         * @return Un vector con los planes.
         */
    	static std::vector<Plan*> *getPlanes(void);

        //! Obtiene los bloques de un plan.
        /*!
         * Obtiene los bloques de la base de datos que pertenezcan a un
         * dado plan.
         * @param plan Plan del cual se obtienen los bloques.
         * @return Un vector con los bloques del plan.
         */
    	static std::vector<Bloque*> *getBloques(Plan *plan);

        //! Obtiene los cursos de un bloque.
        /*!
         * Obtiene los cursos de la base de datos que pertenezcan a un
         * dado bloque.
         * @param bloque Bloque sel cual se obtiene los cursos.
         * @return Un vector con los cursos del bloque.
         */
    	static std::vector<Curso*> *getCursos(Bloque *bloque);
};
#endif
