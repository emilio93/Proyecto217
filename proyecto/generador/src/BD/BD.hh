/* copyright 2015 palomosFantásticos */

#ifndef CLASE_BD
#define CLASE_BD

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <string>

//! Conexión con la base de datos.
/**
 * La clase BD crea una conexion con la base de datos y da acceso a esta.
 */
class BD {
    private:
        //! La conexión con la base de datos.
        /*!
         * La conexión con la base de datos.
         */
        sql::Connection *con;

    public:
        //! Obtiene una conexión con la base de datos.
        /*!
         * Crea y devuelve la conexión con la base de datos.
         * @return  La conexión con la base de datos
         */
        sql::Connection *conectar(void);

        /*!
         * Imprime un error pertinente en caso de excepción.
         * @param e La excepción.
         */
        static void manejarExcepcion(sql::SQLException &e, int line,
            const char *function, const char *file);

        //! Llena la base de datos con instantes útiles.
        /*!
         * Llena la base de datos con instantes cada hora si estos no existen.
         * @return True si se han agregado instantes.
         */
        bool llenarInstante(void);

        //! LLena los posibles periodos en que se imparten clases de 2 y 3
        //! horas.
        /*!
         * LLena la base de datos con los periodos en que se puede impartir
         * clases de 2 y 3 horas.
         * @return  True si se han agregado periodos
         *
         * TODO implementar
         */
        bool llenarPeriodoCursos(void);

        //! Destruye la conexión con la base de datos.
        /*!
         * Destruye la conexión con la base de datos.
         */
        ~BD();
};
#endif
