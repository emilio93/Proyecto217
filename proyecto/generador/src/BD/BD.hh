#ifndef CLASE_BD
#define CLASE_BD

#include <string>

#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

/**
 * @breif La clase BD crea una conexion con la base de datos y da acceso a esta.
 */
class BD {
    private:
        sql::Connection *con;
    public:
        sql::Connection conectar(string user, string pass);

        ~BD();
}

#endif
