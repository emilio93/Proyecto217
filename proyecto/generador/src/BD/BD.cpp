/* copyright 2015 palomosFantásticos */

#include <stdlib.h>
#include <stddef.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <string>

#include "BD.hh"
#include "../Instante.hh"
#include "../Dia.hh"

sql::Connection *BD::conectar(void) {
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
        BD::manejarExcepcion(e);
    }
    return this->con;
}

void BD::manejarExcepcion(sql::SQLException &e) {
    std::cout << "# ERR: SQLException in " << __FILE__;
    std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__;
    std::cout << std::endl << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}

bool BD::llenarInstante(void) {
    bool insertados = false;
    unsigned int cantidadDias = 8;  // 7 + INDEFINIDO
    unsigned int cantidadHoras = 24;
    sql::Connection *con = this->conectar();
    sql::PreparedStatement *prep_stmt;
    // sql::ResultSet *res;

    prep_stmt = con->prepareStatement("INSERT INTO Instante (dia, hora, minuto) VALUES (?, ?, 0)");
    for (size_t i = 0; i < cantidadDias; i++) {
        prep_stmt->setInt(1, i);
        for (size_t j = 0; j < cantidadHoras; j++) {
            prep_stmt->setInt(2, j);
            try {
                prep_stmt->executeQuery();
                insertados = true;
            } catch (sql::SQLException &e) {
                std::string error(e.what());
                if (error.find("Duplicate entry") == std::string::npos) {
                    BD::manejarExcepcion(e);
                }
            }  // TRY CATCH
        }  // FOR HORAS
    }  // FOR DIAS
    return insertados;
}

BD::~BD() {
    delete this->con;
}

void testBD(void) {
    using std::cout;
    using std::endl;

    cout << "Creando objeto BD..." << endl;
    BD *bd = new BD();
    cout << "OK!" << std::endl;
    cout << "Conectando a base de datos..." << endl;

    sql::Connection * con = bd->conectar();

    cout << "Llenando tabla Instante" << endl;
    if (bd->llenarInstante()) {
        cout << "Se han insertado valores en tabla Instante" << endl;
    } else {
        cout << "No se han insertado valores en tabla Instante" << endl;
    }

    cout << "Bien si no hubo errores!" << endl;
    cout << "Cerrando conexion..." << endl;
    delete con;
    cout << "Bien si no hubo errores!" << endl;
}
