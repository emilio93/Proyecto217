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
#include <cppconn/prepared_statement.h>

#include "BD.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"

using namespace std;

std::vector<Plan*> * Serializacion::getPlanes(void) {
    std::vector<Plan*> * planes = new std::vector<Plan*>();
    try {
        sql::Connection * con = Serializacion::getCon();
        sql::Statement * stmt;
        sql::ResultSet * res;


        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from Plan");
        cout << "Tabla Plan" << endl;
        cout << "--------------" << endl;
        cout << "id | nombre" << endl;
        cout << "---+------------" << endl;
        while (res->next()) {
            /* Access column data by alias or column name */
            cout << res->getString("id");
            cout << "  | ";
            /* Access column fata by numeric offset, 1 is the first column */
            cout << res->getString("nombre") << endl;

            //AHORA SI
            int id = res->getInt("id");
            std::string nombre = res->getString("nombre").c_str();
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
    int id = plan->getId();

    std::vector<Bloque*> * bloques = new std::vector<Bloque*>();
    try {
        sql::Connection * con = Serializacion::getCon();
        sql::PreparedStatement * prep_stmt;
        sql::ResultSet * res;

        prep_stmt = con->prepareStatement("SELECT * from Bloque WHERE idPlan = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            //AHORA SI
            int idBloque = res->getInt("id");
            int semestre = res->getInt("semestre");
            Bloque * bloque = new Bloque(idBloque, plan, semestre);
            bloques->push_back(bloque);
        }
        delete res;
        delete prep_stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return bloques;
}

std::vector<Curso*> * Serializacion::getCursos(Bloque * bloque) {
    int id = bloque->getId();

    std::vector<Curso*> * cursos = new std::vector<Curso*>();
    try {
        sql::Connection * con = Serializacion::getCon();
        sql::PreparedStatement * prep_stmt;
        sql::ResultSet * res;

        prep_stmt = con->prepareStatement("SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla FROM Curso INNER JOIN CursosBloque ON CursosBloque.idCurso = Curso.id INNER JOIN Bloque ON Bloque.id = CursosBloque.idBloque WHERE Bloque.id = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            //AHORA SI
            int idCurso = res->getInt("id");
            int cantidadHoras = res->getInt("cantidadHoras");
            int clasesEnSemana = res->getInt("clasesEnSemana");
            int cantidadGrupos = res->getInt("cantidadGrupos");
            std::string nombre =  res->getString("nombre").c_str();
            std::string sigla =  res->getString("sigla").c_str();
            Curso * curso = new Curso(idCurso, cantidadHoras, clasesEnSemana, cantidadGrupos, nombre, sigla);
            cursos->push_back(curso);
        }
        delete res;
        delete prep_stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return cursos;
}

sql::Connection * Serializacion::getCon(void) {
    BD * bd = new BD();
    sql::Connection * con = bd->conectar();
    return con;
}

int testSerializacion(void) {
    std::vector<Plan*> * planes = Serializacion::getPlanes();
    std::cout << std::endl;
    for (int i = 0; i < planes->size(); i++) {
        std::cout << "Plan: " << planes->at(i)->getNombre() << std::endl;
        std::vector<Bloque*> * bloques = planes->at(i)->getBloques();
        for (int j = 0; j < bloques->size(); j++) {
            std::cout << "\tBloque " << bloques->at(j)->getId() <<": ";
            std::cout << "Semestre " << bloques->at(j)->getSemestre();
            std::cout << std::endl;
            std::vector<Curso*> * cursos = bloques->at(j)->getCursos();
            for (int k = 0; k < cursos->size(); k++) {
                std::cout << "\t\tCurso " << cursos->at(k)->getNombre();
                std::cout << " - " << cursos->at(k)->getSigla();
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
