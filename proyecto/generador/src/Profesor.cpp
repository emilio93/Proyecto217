/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Profesor.hh"
#include "Misc.hh"

/*******************************************************************************
 ** ATRIBUTOS ESTÁTICOS PRIVADOS
 ******************************************************************************/

int Profesor::ID = 0;
int Profesor::HORAS_LABORALES = 0;
std::string Profesor::NOMBRE = "";
std::string Profesor::APELLIDO = "";
std::vector<Curso> *Profesor::CURSOS_DADOS = NULL;

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

// SIGNATURE
// Profesor(int id = ID, int horasLaborales = HORAS_LABORALES,
// std::string nombre = NOMBRE, std::string apellido = APELLIDO,
// std::vector<Curso> *cursosDados = CURSOS_DADOS);
Profesor::Profesor(int id, int horasLaborales, std::string nombre,
    std::string apellido, std::vector<Curso> *cursosDados) {
    this->setId(id);
    this->setHorasLaborales(horasLaborales);
    this->horasAsignadas = 0;  // NINGUNA HASTA EL MOMENTO
    this->nombre = nombre;
    this->apellido = apellido;
    this->cursosDados = cursosDados;
}

void Profesor::setId(int id) {
    this->id = id;
}

void Profesor::setHorasLaborales(int horasLaborales) {
    this->horasLaborales = horasLaborales;
}

std::vector<Profesor> *Profesor::getProfesores(Curso &curso) {
    return NULL;
}

int Profesor::getId(void) {
    return this->id;
}

std::string Profesor::getNombre(void) {
    return this->nombre;
}

std::string Profesor::getApellido(void) {
    return this->apellido;
}

bool Profesor::estoyDisponible(std::vector<IPeriodo*> *horarioGrupo) {
    // Falta implementar
    return false;
}

bool Profesor::igual(Profesor *profesor) {
    return this->getNombre() == profesor->getNombre() &&
        this->getApellido() == profesor->getApellido();
}



std::vector <IPeriodo*> *Profesor::getHorario(void) {
    // Faltan Implementar
    return NULL;
}

bool Profesor::verificarCurso(Curso *cursoPrueba) {
    std::vector<int>::size_type size = this->cursosDados->size();

    bool doyCurso = false;

    for (size_t i = 0; i < size; i++) {
        if (this->cursosDados->at(i).igual(cursoPrueba)) {
            doyCurso = true;
        }
        /* else {

            return 0;
        } */
    }
    return doyCurso;
}


// Problemas con el this...
void Profesor::asignarGrupo(Grupo *grupo) {
    // cursosDados.push_back(*grupo);
    // grupo->push_back(*cursosDados);
    this->gruposAsignados->push_back(*grupo);
}



/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

// NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 */
void testProfesor(void) {
    using std::cout;
    using std::endl;
}
