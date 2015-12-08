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
#include "../Dia.hh"
#include "../Plan.hh"
#include "../Bloque.hh"
#include "../Curso.hh"
#include "../Instante.hh"
#include "../IInstante.hh"
#include "../Periodo.hh"
#include "../IPeriodo.hh"
#include "../Profesor.hh"


/*******************************************************************************
 ** ATRIBUTOS ESTÁTICOS PRIVADOS
 ******************************************************************************/

std::vector<Profesor> Serializacion::profesoresExistentes =
    std::vector<Profesor>();

std::vector<Curso> Serializacion::cursosExistentes = std::vector<Curso>();

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

std::vector<Plan> *Serializacion::getPlanes(void) {
    std::vector<Plan> *planes = new std::vector<Plan>();
    try {
         sql::Connection *con = Serializacion::getCon();
         sql::Statement *stmt;
         sql::ResultSet *res;

         stmt = con->createStatement();
         res = stmt->executeQuery("SELECT * from Plan");
         while (res->next()) {
             int id = res->getInt("id");
             std::string nombre = res->getString("nombre").c_str();
             Plan plan = Plan(id, nombre);
             planes->push_back(plan);
         }
         delete res;
         delete stmt;
         delete con;
     } catch (sql::SQLException &e) {
         BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
     }
     return planes;
}

std::vector<Bloque> *Serializacion::getBloques(Plan &plan) {
    int id = plan.getId();

    std::vector<Bloque> *bloques = new std::vector<Bloque>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement(
            "SELECT * from Bloque WHERE idPlan = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            int idBloqueTmp = res->getInt("id");
            int idBloque = idBloqueTmp;
            int semestre = res->getInt("semestre");
            bloques->push_back(Bloque(idBloque, plan, semestre));
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return bloques;
}

std::vector<Curso> *Serializacion::getCursos(Bloque &bloque) {
    int id = bloque.getId();

    std::vector<Curso> *cursos = new std::vector<Curso>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement(
            "SELECT "
                "Curso.id, Curso.cantidadHoras, Curso.clasesEnSemana, "
                "Curso.cantidadGrupos, Curso.nombre, Curso.sigla "
            "FROM Curso "
            "INNER JOIN CursosBloque "
            "ON CursosBloque.idCurso = Curso.id "
            "INNER JOIN Bloque "
            "ON Bloque.id = CursosBloque.idBloque "
            "WHERE Bloque.id = ?");

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
                delete curso;
                curso = Serializacion::buscarCurso(curso);
            } else {
                Serializacion::cursosExistentes.push_back(*curso);
            }
            cursos->push_back(*curso);
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return cursos;
}

std::vector<Profesor> *Serializacion::getProfesores(Curso &curso) {
    int id = curso.getId();

    std::vector<Profesor> *profesores = new std::vector<Profesor>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *prep_stmt;
        sql::ResultSet *res;

        prep_stmt = con->prepareStatement(
            "SELECT "
                "Profesor.id, Profesor.horasLaborales, Profesor.nombre, "
                "Profesor.apellido "
            "FROM Profesor "
            "INNER JOIN ProfesoresCurso "
            "ON Profesor.id = ProfesoresCurso.idProfesor "
            "INNER JOIN Curso "
            "ON Curso.id = ProfesoresCurso.idCurso "
            "WHERE Curso.id = ?");

        prep_stmt->setInt(1, id);
        res = prep_stmt->executeQuery();

        while (res->next()) {
            int idProfe = res->getInt("id");
            int horasLaboralesProfe = res->getInt("horasLaborales");
            std::string nombreProfe = res->getString("nombre").c_str();
            std::string apellidoProfe = res->getString("apellido").c_str();

            Profesor *profe = new Profesor(idProfe, horasLaboralesProfe,
                nombreProfe, apellidoProfe);

            if (Serializacion::buscarProfesor(profe) != NULL) {
                delete profe;
                profe = Serializacion::buscarProfesor(profe);
            } else {
                Serializacion::profesoresExistentes.push_back(*profe);
            }
            profesores->push_back(*profe);
        }
        delete res;
        delete prep_stmt;
        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return profesores;
}

std::vector< std::vector<IPeriodo*> > *Serializacion::getPeriodos(
    Curso &curso) {
    int id = curso.getId();
    std::vector< std::vector<IPeriodo*> > *posiblesHorarios =
        new std::vector< std::vector<IPeriodo*> >();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *stmtInicio;
        sql::PreparedStatement *stmtFin;
        sql::ResultSet *resInicio;
        sql::ResultSet *resFin;

        stmtInicio = con->prepareStatement(
            "SELECT "
                "Instante.dia, Instante.hora, Instante.minuto "
            "FROM Instante "
            "INNER JOIN Periodo ON Instante.id = Periodo.idInstanteInicio "
            "INNER JOIN HorariosCurso ON Periodo.id = HorariosCurso.idPeriodo "
            "WHERE HorariosCurso.idCurso = ?");



        stmtFin = con->prepareStatement(
            "SELECT "
                "Instante.dia, Instante.hora, Instante.minuto "
            "FROM Instante "
            "INNER JOIN Periodo ON Instante.id = Periodo.idInstanteFin "
            "INNER JOIN HorariosCurso ON Periodo.id = HorariosCurso.idPeriodo "
            "WHERE HorariosCurso.idCurso = ?");

        stmtInicio->setInt(1, id);
        stmtFin->setInt(1, id);

        resInicio = stmtInicio->executeQuery();
        resFin = stmtFin->executeQuery();

        // Se utiliza para conocer la cantidad de periodos que lleva un
        // posible horario de un curso, y asignar los vectores de IPerioco
        // según corresponda.
        int c = 0;

        std::vector<IPeriodo*> horario = std::vector<IPeriodo*>();
        while (resInicio->next() && resFin->next()) {
            if (++c == curso.getClasesEnSemana()) {
                posiblesHorarios->push_back(horario);
                std::vector<IPeriodo*> horario = std::vector<IPeriodo*>();
                c = 0;
            }
            IPeriodo *periodoHorario = new Periodo(
                new Instante(
                    intToDia(resInicio->getInt("dia")),
                    resInicio->getInt("hora"),
                    resInicio->getInt("minuto")),
                new Instante(
                    intToDia(resFin->getInt("dia")),
                    resFin->getInt("hora"),
                    resFin->getInt("minuto")));
            horario.push_back(periodoHorario);
        }

        delete resInicio;
        delete resFin;

        delete stmtInicio;
        delete stmtFin;

        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return posiblesHorarios;
}

std::vector<IPeriodo*> *Serializacion::getPeriodos(Profesor &profesor) {
    int id = profesor.getId();
    std::vector<IPeriodo*> *horariosProfesor = new std::vector<IPeriodo*>();
    try {
        sql::Connection *con = Serializacion::getCon();
        sql::PreparedStatement *stmtInicio;
        sql::PreparedStatement *stmtFin;
        sql::ResultSet *resInicio;
        sql::ResultSet *resFin;

        stmtInicio = con->prepareStatement(
            "SELECT "
                "Instante.dia, Instante.hora, Instante.minuto "
            "FROM Instante "
            "INNER JOIN Periodo "
            "ON Instante.id = Periodo.idInstanteInicio "
            "INNER JOIN HorariosProfesor "
            "ON Periodo.id = HorariosProfesor.idPeriodo "
            "WHERE Profesor.id = ?");

        stmtFin = con->prepareStatement(
            "SELECT "
                "Instante.dia, Instante.hora, Instante.minuto "
            "FROM Instante "
            "INNER JOIN Periodo "
            "ON Instante.id = Periodo.idInstanteFin "
            "INNER JOIN HorariosProfesor "
            "ON Periodo.id = HorariosProfesor.idPeriodo "
            "WHERE Profesor.id = ?");

        stmtInicio->setInt(1, id);
        stmtFin->setInt(1, id);

        resInicio = stmtInicio->executeQuery();
        resFin = stmtFin->executeQuery();

        while (resInicio->next() && resFin->next()) {
            IPeriodo *periodoHorario = new Periodo(
                new Instante(
                    intToDia(resInicio->getInt("dia")),
                    resInicio->getInt("hora"),
                    resInicio->getInt("minuto")),
                new Instante(
                    intToDia(resFin->getInt("dia")),
                    resFin->getInt("hora"),
                    resFin->getInt("minuto")));
            horariosProfesor->push_back(periodoHorario);
        }

        delete resInicio;
        delete resFin;

        delete stmtInicio;
        delete stmtFin;

        delete con;
    } catch (sql::SQLException &e) {
        BD::manejarExcepcion(e, __LINE__, __FUNCTION__, __FILE__);
    }
    return horariosProfesor;
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

sql::Connection *Serializacion::getCon(void) {
    BD *bd = new BD();
    sql::Connection *con = bd->conectar();
    return con;
}

Curso *Serializacion::buscarCurso(Curso *curso) {
    Curso *existente = NULL;
    for (size_t i = 0; i < Serializacion::cursosExistentes.size(); i++) {
        if (Serializacion::cursosExistentes.at(i).igual(curso)) {
            existente = &Serializacion::cursosExistentes.at(i);
            break;
        }
    }
    return existente;
}

Profesor *Serializacion::buscarProfesor(Profesor *profesor) {
    Profesor *existente = NULL;
    for (size_t i = 0; i < Serializacion::profesoresExistentes.size(); i++) {
        if (Serializacion::profesoresExistentes.at(i).igual(profesor)) {
            existente = &Serializacion::profesoresExistentes.at(i);
            break;
        }
    }
    return existente;
}

/*******************************************************************************
 ** MÉTODO DE PRUEBA
 ******************************************************************************/

void testSerializacion(void) {
    using std::cout;
    using std::endl;
    using std::vector;

    vector<Plan> *planes = Serializacion::getPlanes();

    for (unsigned int i = 0; i < planes->size(); i++) {
        cout << "Plan: " << planes->at(i).getNombre() << endl;

        vector<Bloque> *bloques = planes->at(i).getBloques();

        for (unsigned int j = 0; j < bloques->size(); j++) {
            cout << "\tBloque " << bloques->at(j).getId() <<": ";
            cout << "Semestre " << bloques->at(j).getSemestre() << endl;

            vector<Curso> *cursos = bloques->at(j).getCursos();

            for (unsigned int k = 0; k < cursos->size(); k++) {
                cout << "\t\tCurso " << cursos->at(k).getNombre();
                cout << " - " << cursos->at(k).getSigla() << endl;

                vector<Profesor> *profesores = cursos->at(k).getProfesores();

                for (size_t l = 0; l < profesores->size(); l++) {
                    cout << "\t\t\tProfesor: " << profesores->at(l).getNombre();
                    cout << " " << profesores->at(l).getApellido() << endl;
                }  // Profesores
                delete profesores;
            }  // Cursos
            delete cursos;
        }  // Bloques
        delete bloques;
    }  // Planes
    delete planes;
}
