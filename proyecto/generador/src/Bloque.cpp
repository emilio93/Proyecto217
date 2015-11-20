/* copyright 2015 palomosFantásticos */

#include <vector>

#include "Bloque.hh"
class Plan;

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Bloque::Bloque(int id, Plan &plan, int semestre) {
    this->id = id;
    this->plan = plan;
    this->semestre = semestre;
}

int Bloque::getSemestre(void) {
    return this->semestre;
}

int Bloque::getId(void) {
    return this->id;
}

std::vector<Curso> *Bloque::getCursos(void) {
    return Serializacion::getCursos(*this);
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

// NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 */
void testBloque(void) {
    using std::cout;
    using std::endl;
}
