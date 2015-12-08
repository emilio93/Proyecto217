/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"
#include "Profesor.hh"

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Grupo::Grupo(Curso *curso) {
    this->curso = curso;
}

int Grupo::getId(void) {
    return this->id;
}

void Grupo::setId(int id) {
    this->id = id;
}

Curso *Grupo::getCurso(void) {
    return this->curso;
}

void Grupo::setCurso(Curso *curso) {
    this->curso = curso;
}

Profesor *Grupo::getProfesor(void) {
    return this->profesor;
}

void Grupo::setProfesor(Profesor *profesor) {
    this->profesor = profesor;
}

std::vector< std::vector<IPeriodo*> > *Grupo::getHorario() {
    return this->horario;
}

void Grupo::setHorario(std::vector< std::vector<IPeriodo*> > *horario) {
    this->horario = horario;
}

std::vector<Profesor> *Grupo::getPosiblesProfesores(void) {
    return this->getCurso()->getProfesores();
}

bool Grupo::asignarProfesor(Profesor *profesor) {
    bool asignado = false;
    profesor->asignarGrupo(this);
    this->setProfesor(profesor);
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/


/**
 * @brief Main para probar la implementación de la clase.
 */
void testGrupo(void) {
    using std::cout;
    using std::endl;
}
