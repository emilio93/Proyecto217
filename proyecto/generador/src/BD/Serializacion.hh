/* copyright 2015 palomosFantásticos */

#ifndef CLASE_SERIALIZACION
#define CLASE_SERIALIZACION

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <string>
#include <vector>

#include "BD.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"
#include "../Profesor.hh"

//! Consulta y obtiene datos de la base de datos, los convierte a objetos .
/*!
 * La clase Serializacion se encarga de convertir los resultados de la
 * base de datos en los objetos pertinentes.
 */
class Serializacion {
     private:
        //! Un set de los cursos que ya han sido creados.
        /*!
         *  Un set de los cursos que ya han sido creados, sirve para no repetir
         *  la creación de un curso ya existente.
         */
        static std::vector<Curso> cursosExistentes;

        //! Un set de los profesotes que ya han sido creados.
        /*!
         *  Un set de los cursos que ya han sido creados, sirve para no repetir
         *  la creación de un profesor ya existente.
         */
        static std::vector<Profesor> profesoresExistentes;

        //! Obtiene una conexión con la base de datos.
        /*!
         * Obtiene una conexión con el servidor de la base de datos.
         * @return  La conexión con la base de datos.
         */
        static sql::Connection *getCon(void);

        //! Busca un curso dentro de los ya creados.
        /*!
         * Busca dentro de los cursos existentes un curso dado.
         * @param  curso El curso a buscar.
         * @return       El curso encontrado o NULL si no existe.
         */
        static Curso *buscarCurso(Curso *curso);

        //! Busca un profesor dentro de los ya creados.
        /*!
         * Busca dentro de los profesores existentes un profesor dado.
         * @param  profesor El profesor a buscar.
         * @return          El profesor encontrado o NULL si no existe.
         */
        static Profesor *buscarProfesor(Profesor *profesor);

     public:
        //! Obtiene los planes existentes en la base de datos.
        /*!
         * Obtiene una lista de los planes disponibles en la base de
         * datos.
         * @return Un set con los planes.
         */
        static std::vector<Plan> *getPlanes(void);

        //! Obtiene los bloques de un plan.
        /*!
         * Obtiene los bloques de la base de datos que pertenezcan a un
         * dado plan.
         * @param plan Plan del cual se obtienen los bloques.
         * @return Un vector con los bloques del plan.
         */
        static std::vector<Bloque> *getBloques(Plan &plan);

        //! Obtiene los cursos de un bloque.
        /*!
         * Obtiene los cursos de la base de datos que pertenezcan a un
         * dado bloque.
         * @param bloque Bloque sel cual se obtiene los cursos.
         * @return Un set con los cursos del bloque.
         */
        static std::vector<Curso> *getCursos(Bloque &bloque);

        //! Obtiene los profesores que dan un curso.
        /*!
         * Obtiene todos los profesores que imparten un curso.
         * @param curso Curso del cual se buscan los profesores.
         * @return Un set con los profesores que dan el curso.
         *
         * TODO
         */
        static std::vector<Profesor> *getProfesores(Curso &curso);

        //! Obtiene los posibles horarios para un curso.
        /*!
         * Obtiene los posibles horarios en forma de vectores de periodos en los
         * que el curso se acomoda de manera adecuada.
         * @param curso Se utiliza para buscar según parámetros de
         * clasesEnSemana y de clasesPorPeriodo.
         * @return Un vector con los posibles horarios(vector de IPeriodos) de
         * un Curso.
         *
         * TODO
         */
        static std::vector< std::vector<IPeriodo*> > *getPeriodos(Curso &curso);

        //! Obtiene los periodos en que un profesor está disponilbe.
        /*!
         * Obtiene los periodos en que un profesor está disponilbe.
         * @param profesor El profesor del cual se obtienen los periodos.
         */
        static std::vector<IPeriodo*> *getPeriodos(Profesor &profesor);

        /*!
         * Busca el id de un Periodo especificado. En caso de no encontrarlo lo
         * crea y devuelve el id de este.
         * @return El id del periodo especificado.
         */
        static int buscarIdPeriodo(IPeriodo *periodo);
};
#endif
