#include <iostream>
#include <stddef.h>//This gets NULL

#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

#include "BD.hh"
using sql;

sql::Connection * BD::conectar() {
    try {
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::MySQL_Driver::get_mysql_driver_instance();
        this->con = driver->connect("tcp://127.0.0.1:3306", "user", "password");
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return this->con;
}

BD::~BD() {
    delete this->con;
}
