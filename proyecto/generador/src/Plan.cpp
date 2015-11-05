#include <iostream>
#include <stddef.h>
#include <string>

#include "Plan.hh"

Plan::Plan(int id, std::string nombre) {
    this->setId(id);
    this->setNombre(nombre);
}

int Plan::getId(void) {
    return this->id;
}

void Plan::setId(int id) {
    this->id = id;
}

std::string Plan::getNombre(void) {
    return this->nombre;
}

void Plan::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::vector<Bloque*> * Plan::getBloques(void) {
    return Serializacion::getBloques(this);
}

int testPlan(void) {
    Plan * plan = new Plan(1,"hola");
    std::cout << plan->getNombre() << std::endl;
    return 0;
}
