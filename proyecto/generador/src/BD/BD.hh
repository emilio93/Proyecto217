#ifndef CLASE_BD
#define CLASE_BD

#include <string>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/**
 * @breif La clase BD crea una conexion con la base de datos y da acceso a esta.
 */
class BD {
    private:
        sql::Connection *con;
    public:
        sql::Connection * conectar(void);

        ~BD();
};

#endif
