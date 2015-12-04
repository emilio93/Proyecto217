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

std::string BD::USER = "root";
std::string BD::PASS = "pass";
std::string BD::HOST = "tcp://127.0.0.1:3306";
std::string BD::NAME = "horarios";

sql::Connection *BD::conectar(bool db) {
    try {
        sql::Driver * driver;
        driver = get_driver_instance();
        this->con = driver->connect(BD::HOST, BD::USER, BD::PASS);
        if (db) {
            this->con->setSchema(BD::NAME);
        }
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return this->con;
}

void BD::manejarExcepcion(sql::SQLException &e, int line,
    const char *function, const char *file) {
    std::cout << "# ERR: SQLException in " << file;
    std::cout << "(" << function << ") on line " << line;
    std::cout << std::endl << "# ERR: " << e.what();
    std::cout << " (MySQL error code: " << e.getErrorCode();
    std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
}

bool BD::chequearBaseDeDatos(void) {
    bool correcto = true;
    sql::Connection *con = this->conectar(false);
    sql::PreparedStatement *prep_stmt;
    sql::ResultSet *res;
    try {
        prep_stmt = con->prepareStatement(
            "SELECT * FROM information_schema.schemata "
            "WHERE schema_name = ? LIMIT 1");
        prep_stmt->setString(1, BD::NAME);
        res = prep_stmt->executeQuery();
        correcto = correcto && res->rowsCount() != 0;

        if (correcto) {
            prep_stmt = con->prepareStatement(
                "SELECT * "
                "FROM information_schema.tables "
                "WHERE table_schema = 'horarios' "
                    "AND table_name = ? "
                "LIMIT 1");

            std::string tablas[] = { "Bloque", "Curso", "CursosBloque", "Grupo",
                "GruposHorario", "Horario", "HorariosCurso", "Instante",
                "Periodo", "PeriodoGrupo", "PeriodoProfesor", "Plan",
                "Profesor", "ProfesoresCurso"};

            for (size_t i = 0; i < sizeof(tablas)/sizeof(tablas[0]); i++) {
                prep_stmt->setString(1, tablas[i]);
                res = prep_stmt->executeQuery();
                correcto = correcto && res->rowsCount() != 0;
                if (!correcto) {
                    break;
                }
            }
        }
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }

    delete con;
    delete prep_stmt;
    delete res;

    return correcto;
}

bool BD::llenarInstante(void) {
    bool insertados = false;
    unsigned int cantidadDias = 8;  // 7 + INDEFINIDO
    unsigned int cantidadHoras = 24;
    sql::Connection *con = this->conectar();
    sql::PreparedStatement *prep_stmt;
    // sql::ResultSet *res;

    prep_stmt = con->prepareStatement(
        "INSERT "
        "INTO Instante (dia, hora, minuto) "
        "VALUES (?, ?, 0)");
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
                    BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
                }
            }  // TRY CATCH
        }  // FOR HORAS
    }  // FOR DIAS
    return insertados;
}

bool BD::llenarPeriodoCursos(void) {
    bool insertados = false;

    unsigned int cantidadDias = 8;
    unsigned int cursos2horas = 7;
    unsigned int cursos3horas = 5;
    unsigned int inicioDia = 7;  // 7AM

    sql::Connection *con = this->conectar();
    sql::PreparedStatement *main_stmt;
    sql::PreparedStatement *search_stmt;
    sql::ResultSet *search_res;

    search_stmt = con->prepareStatement(
        "SELECT id FROM Instante WHERE dia = ? AND hora = ? AND minuto = 0");
    main_stmt = con->prepareStatement(
        "INSERT INTO Periodo (idInstanteInicio, idInstanteFin) VALUES (?, ?)");
    for (size_t i = 0; i < cantidadDias; i++) {
        search_stmt->setInt(1, i);
        int idInicio;
        int idFin;
        for (size_t j = 0; j < cursos2horas; j++) {
            search_stmt->setInt(2, inicioDia + j*2);
            try {
                search_res = search_stmt->executeQuery();
                if (search_res->rowsCount() > 0) {
                    search_res->next();
                    idInicio = search_res->getInt("id");
                } else {
                    continue;
                }
            } catch (sql::SQLException &e) {
                BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
            }

            search_stmt->setInt(2, inicioDia + (j+1)*2);
            try {
                search_res = search_stmt->executeQuery();
                if (search_res->rowsCount() > 0) {
                    search_res->next();
                    idFin = search_res->getInt("id");
                } else {
                    continue;
                }
            } catch (sql::SQLException &e) {
                BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
            }

            main_stmt->setInt(1, idInicio);
            main_stmt->setInt(2, idFin);
            try {
                main_stmt->executeQuery();
                insertados = true;
            } catch (sql::SQLException &e) {
                std::string error(e.what());
                if (error.find("Duplicate entry") == std::string::npos) {
                    BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
                }
            }
        }
        for (size_t j = 0; j < cursos3horas; j++) {
            search_stmt->setInt(2, inicioDia + j*3);
            try {
                search_res = search_stmt->executeQuery();
                if (search_res->rowsCount() > 0) {
                    search_res->next();
                    idInicio = search_res->getInt("id");
                } else {
                    continue;
                }
            } catch (sql::SQLException &e) {
                BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
            }

            search_stmt->setInt(2, inicioDia + (j+1)*3);
            try {
                search_res = search_stmt->executeQuery();
                if (search_res->rowsCount() > 0) {
                    search_res->next();
                    idFin = search_res->getInt("id");
                } else {
                    continue;
                }
            } catch (sql::SQLException &e) {
                BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
            }

            main_stmt->setInt(1, idInicio);
            main_stmt->setInt(2, idFin);
            try {
                main_stmt->executeQuery();
                insertados = true;
            } catch (sql::SQLException &e) {
                std::string error(e.what());
                if (error.find("Duplicate entry") == std::string::npos) {
                    BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
                }
            }
        }
    }
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

    cout << "Chequeando correctitud de la base de datos..." << endl;
    if (bd->chequearBaseDeDatos()) {
        cout << "OK!" << std::endl;
    } else {
        cout << "La base de datos no cumple los requerimientos" << endl;
        return;
    }

    cout << "Conectando a base de datos..." << endl;

    sql::Connection * con = bd->conectar();

    cout << "Llenando tabla Instante" << endl;
    if (bd->llenarInstante()) {
        cout << "Se han insertado valores en tabla Instante" << endl;
    } else {
        cout << "No se han insertado valores en tabla Instante" << endl;
    }

    cout << "Llenando tabla Periodo" << endl;
    if (bd->llenarPeriodoCursos()) {
        cout << "Se han insertado valores en tabla Periodo" << endl;
    } else {
        cout << "No se han insertado valores en tabla Periodo" << endl;
    }

    cout << "Bien si no hubo errores!" << endl;
    cout << "Cerrando conexion..." << endl;
    delete con;
    cout << "Bien si no hubo errores!" << endl;
}
