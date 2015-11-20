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
    this->id = id;
    this->horasLaborales = horasLaborales;
    this->horasAsignadas = 0;  // NINGUNA HASTA EL MOMENTO
    this->nombre = nombre;
    this->apellido = apellido;
    this->cursosDados = cursosDados;
}

std::string Profesor::getNombre(void) {
    return this->nombre;
}

std::string Profesor::getApellido(void) {
    return this->apellido;
}


bool Profesor::igual(Profesor *profesor) {
    return this->getNombre() == profesor->getNombre() &&
        this->getApellido() == profesor->getApellido();
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
