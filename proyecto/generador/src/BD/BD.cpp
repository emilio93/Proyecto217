#include <stdlib.h>
#include <stddef.h>

#include <iostream>
#include <string>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "BD.hh"

sql::Connection * BD::conectar(void) {

    std::string dbUser = "root";
    std::string dbPass = "pass";
    std::string dbHost = "tcp://127.0.0.1:3306";
    std::string dbName = "horarios";

    try {
        sql::Driver * driver;

        driver = get_driver_instance();
        this->con = driver->connect(dbHost, dbUser, dbPass);
        this->con->setSchema(dbName);
    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
    return this->con;
}

BD::~BD() {
    delete this->con;
}

int testBD(void) {
    using namespace std;
    cout << "Creando objeto BD..." << endl;
    BD * bd = new BD();
    cout << "OK!" << std::endl;
    cout << "Conectando a base de datos..." << endl;

    sql::Connection * con = bd->conectar();

    cout << "Bien si no hubo errores!" << endl;
    cout << "Cerrando conexion..." << endl;
    delete con;
    cout << "Bien si no hubo errores!" << endl;

    return 0;
}
