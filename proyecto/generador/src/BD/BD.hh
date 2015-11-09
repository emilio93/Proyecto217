#ifndef CLASE_BD
#define CLASE_BD

#include <string>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

//! Conexión con la base de datos.
/**
 * La clase BD crea una conexion con la base de datos y da acceso a esta.
 */
class BD {
    private:
        /**
         * @breif La conexión con la base de datos.
         */
        sql::Connection *con;
    public:
        /**
         * @breif Crea y devuelve la conexión con la base de datos.
         * @return  La conexión con la base de datos
         */
        sql::Connection *conectar(void);

        /**
         * @breif Destruye la conexión con la base de datos.
         */
        ~BD();
};
#endif
