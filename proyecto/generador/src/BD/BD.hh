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
        static void manejarExcepcion(sql::SQLException &e);

        //! Llena la base de datos con instantes útiles.
        /*!
         * Llena la base de datos con instantes cada hora si estos no existen.
         */
        bool llenarInstante(void);

        //! Destruye la conexión con la base de datos.
        /*!
         * Destruye la conexión con la base de datos.
         */
        ~BD();
};
#endif
