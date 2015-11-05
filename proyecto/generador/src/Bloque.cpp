#include "Bloque.hh"
class Plan;

Bloque::Bloque(int id, Plan * plan, int semestre) {
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
std::vector<Curso*> * Bloque::getCursos(void) {
    return Serializacion::getCursos(this);
}
