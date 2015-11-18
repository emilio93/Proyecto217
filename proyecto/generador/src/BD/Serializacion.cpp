/* copyright 2015 palomosFantásticos */

#include <stddef.h>
#include <stdlib.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Serializacion.hh"
#include "BD.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"
#include "../Profesor.hh"


/*******************************************************************************
 ** ATRIBUTOS ESTÁTICOS PRIVADOS
 ******************************************************************************/

std::vector<Profesor*> Serializacion::profesoresExistentes = std::vector<Profesor*>();
std::vector<Curso*> Serializacion::cursosExistentes = std::vector<Curso*>();

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

std::vector<Plan*> *Serializacion::getPlanes(void) {
    std::vector<Plan*> *planes = new std::vector<Plan*>();
    try {
         sql::Connection *con = Serializacion::getCon();
         sql::Statement *stmt;
         sql::ResultSet *res;

         stmt = con->createStatement();
         res = stmt->executeQuery("SELECT * from Plan");
         while (res->next()) {
             int id = res->getInt("id");
             std::string nombre = res->getString("nombre").c_str();
             Plan *plan = new Plan(id, nombre);
             planes->push_back(plan);
         }
         delete res;
         delete stmt;
         delete con;
     } catch (sql::SQLException &e) {
         BD::manejarExcepcion(e);
     }
     return planes;
}

std::vector<Bloque*> *Serializacion::getBloques(Plan *plan) {
    int id = plan->getId();

    std::vector<Bloque*> *bloques = new std::vector<Bloque*>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement("SELECT * from Bloque WHERE idPlan = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            int idBloque = res->getInt("id");
            int semestre = res->getInt("semestre");
            Bloque *bloque = new Bloque(idBloque, plan, semestre);
            bloques->push_back(bloque);
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e);
    }
    return bloques;
}

std::vector<Curso*> *Serializacion::getCursos(Bloque *bloque) {
    int id = bloque->getId();

    std::vector<Curso*> *cursos = new std::vector<Curso*>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement("SELECT Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, Curso.cantidadGrupos, Curso.nombre, Curso.sigla FROM Curso INNER JOIN CursosBloque ON CursosBloque.idCurso = Curso.id INNER JOIN Bloque ON Bloque.id = CursosBloque.idBloque WHERE Bloque.id = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            int idCurso = res->getInt("id");
            int cantidadHoras = res->getInt("cantidadHoras");
            int clasesEnSemana = res->getInt("clasesEnSemana");
            int cantidadGrupos = res->getInt("cantidadGrupos");
            std::string nombre =  res->getString("nombre").c_str();
            std::string sigla =  res->getString("sigla").c_str();
            Curso *curso = new Curso(idCurso, cantidadHoras, clasesEnSemana,
                cantidadGrupos, bloque, nombre, sigla);
            if (Serializacion::buscarCurso(curso) != NULL) {
                curso = Serializacion::buscarCurso(curso);
            } else {
                Serializacion::cursosExistentes.push_back(curso);
            }
            cursos->push_back(curso);
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e);
    }
    return cursos;
}

std::vector<Profesor*> *Serializacion::getProfesores(Curso *curso) {
    int id = curso->getId();

    std::vector<Profesor*> *profesores = new std::vector<Profesor*>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement("SELECT Profesor.id, Profesor.horasLaborales, Profesor.nombre, Profesor.apellido FROM Profesor INNER JOIN Profesor");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e);
    }
    return NULL;
}

std::vector<std::vector<IPeriodo*>*> *Serializacion::getPeriodos(Curso *curso) {
    return NULL;
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

sql::Connection *Serializacion::getCon(void) {
    BD *bd = new BD();
    sql::Connection *con = bd->conectar();
    return con;
}

Curso* Serializacion::buscarCurso(Curso *curso) {
    Curso *existente = NULL;
    for (size_t i = 0; i < Serializacion::cursosExistentes.size(); i++) {
        if (Serializacion::cursosExistentes.at(i)->igual(curso)) {
            existente = Serializacion::cursosExistentes.at(i);
            break;
        }
    }
    return existente;
}

/*******************************************************************************
 ** MÉTODO DE PRUEBA
 ******************************************************************************/

int testSerializacion(void) {
    using std::cout;
    using std::endl;
    using std::vector;

    vector<Plan*> *planes = Serializacion::getPlanes();

    for (unsigned int i = 0; i < planes->size(); i++) {
        cout << "Plan: " << planes->at(i)->getNombre() << endl;

        vector<Bloque*> *bloques = planes->at(i)->getBloques();

        for (unsigned int j = 0; j < bloques->size(); j++) {
            cout << "\tBloque " << bloques->at(j)->getId() <<": ";
            cout << "Semestre " << bloques->at(j)->getSemestre() << endl;

            vector<Curso*> *cursos = bloques->at(j)->getCursos();

            for (unsigned int k = 0; k < cursos->size(); k++) {
                cout << "\t\tCurso " << cursos->at(k)->getNombre();
                cout << " - " << cursos->at(k)->getSigla() << endl;
            }  // Cursos
        }  // Bloques
    }  // Planes
    return 0;
}
