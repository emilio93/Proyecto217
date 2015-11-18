/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <iostream>
#include <string>
#include <vector>

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

std::vector<Plan*> *Plan::getPlanes(void) {
    return Serializacion::getPlanes();
}

std::vector<Bloque*> *Plan::getBloques(void) {
    return Serializacion::getBloques(this);
}

void testPlan(void) {
    using std::cout;
    using std::endl;
    using std::vector;

    std::vector<Plan*> *planes = Plan::getPlanes();

    for (size_t i = 0; i < planes->size(); i++) {
        cout << planes->at(i)->getId() << " - ";
        cout << planes->at(i)->getNombre() << endl;

        std::vector<Bloque*> *bloques = planes->at(i)->getBloques();

        for (size_t j = 0; j < bloques->size(); j++) {
            cout << "\tSemestre: " << bloques->at(j)->getSemestre() << endl;
        }
    }
}
