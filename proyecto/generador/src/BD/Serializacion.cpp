#include <iostream>
#include <string>
#include <stddef.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Serializacion.hh"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "BD.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"

using namespace std;

std::vector<Plan*> * Serializacion::getPlanes(void) {
    sql::Connection * con = Serializacion::getCon();
    std::vector<Plan*> * planes = new std::vector<Plan*>();
    try {
        sql::Statement * stmt;
        sql::ResultSet * res;


        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from tablaPrueba");
        cout << "Tabla Prueba" << endl;
        cout << "--------------" << endl;
        cout << "id | contenido" << endl;
        cout << "---+------------" << endl;
        while (res->next()) {
            /* Access column data by alias or column name */
            cout << res->getString("id");
            cout << "  | ";
            /* Access column fata by numeric offset, 1 is the first column */
            cout << res->getString("contenido") << endl;

            //AHORA SI
            int id = res->getInt("id");
            std::string nombre = res->getString("contenido").c_str();
            Plan * plan = new Plan(id, nombre);
            planes->push_back(plan);
        }
        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return planes;
}

std::vector<Bloque*> * Serializacion::getBloques(Plan * plan) {
    return NULL;
}

std::vector<Curso*> * Serializacion::getCursos(Bloque * bloque) {
    return NULL;
}

sql::Connection * Serializacion::getCon(void) {
    BD * bd = new BD();
    sql::Connection * con = bd->conectar();
    return con;
}

int main(void) {
    std::vector<Plan*> * planes = Serializacion::getPlanes();
    std::cout << std::endl;
    for (int i = 0; i < planes->size(); i++) {
        std::cout << "Plan: " << planes->at(i)->getNombre() << std::endl;
    }
    return 0;
}
