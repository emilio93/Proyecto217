/* copyright 2015 palomosFantásticos */

#include <stddef.h>
#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Curso::Curso(int id, int cantidadHoras, int clasesEnSemana, int cantidadGrupos,
    Bloque *bloque, std::string nombre, std::string sigla) {
    this->setId(id);
    this->setCantidadHoras(cantidadHoras);
    this->setClasesEnSemana(clasesEnSemana);
    this->setCantidadGrupos(cantidadGrupos);
    if (bloque != NULL) {
        this->setBloques(new std::vector<Bloque*>());
        this->getBloques()->push_back(bloque);
    }
    this->setNombre(nombre);
    this->setSigla(sigla);
}

int Curso::getId(void) {
    return this->id;
}

void Curso::setId(int id) {
    this->id = id;
}

int Curso::getCantidadHoras(void) {
    return this->cantidadHoras;
}

void Curso::setCantidadHoras(int cantidadHoras) {
    this->cantidadHoras = cantidadHoras;
}

int Curso::getClasesEnSemana(void) {
    return this->clasesEnSemana;
}

void Curso::setClasesEnSemana(int clasesEnSemana) {
    this->clasesEnSemana = clasesEnSemana;
}

int Curso::getCantidadGrupos(void) {
    return this->cantidadGrupos;
}

void Curso::setCantidadGrupos(int cantidadGrupos) {
    this->cantidadGrupos = cantidadGrupos;
}

std::vector<Bloque*> *Curso::getBloques(void) {
    return this->bloques;
}

void Curso::setBloques(std::vector<Bloque*> *bloques) {
    this->bloques = bloques;
}

std::string Curso::getNombre(void) {
    return this->nombre;
}

void Curso::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Curso::getSigla(void) {
    return this->sigla;
}

void Curso::setSigla(std::string sigla) {
    this->sigla = sigla;
}

std::string Curso::toString(void) {
    return this->getNombre() + " - " + this->getSigla();
}

std::vector<Grupo*> *Curso::crearGrupos(void) {
    std::vector<Grupo*> *grupos = new std::vector<Grupo*>();
    // código
    // TODO(emilio): implementar
    // código
    return grupos;
}

bool Curso::igual(Curso *curso) {
    return this->getSigla().compare(curso->getSigla()) == 0 &&
           this->getNombre().compare(curso->getNombre()) == 0;
}


/*******************************************************************************
 ** MÉTODOS PRIVADOS
  *****************************************************************************/

// NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 */
void testCurso(void) {
    using std::cout;
    using std::endl;

    Curso *curso1 = new Curso(1, 5, 2, 1, NULL,
        "Circuitos Lineles I", "IE0209");
    cout << curso1->toString() << " creado." << endl;
    Curso *curso2 = new Curso(1, 5, 2, 1, NULL,
        "Circuitos Lineles I", "IE0209");
    cout << curso2->toString() << " creado." << endl;
    Curso *curso3 = new Curso(2, 5, 2, 1, NULL,
        "Circuitos Lineles II", "IE0309");
    cout << curso3->toString() << " creado." << endl;

    cout << "Curso1:" << endl;
    cout << "\tid: " << curso1->getId() << endl;
    cout << "\t" << curso1->toString() << endl;
    cout << "\tcantidadHoras: " << curso1->getCantidadHoras() << endl;
    cout << "\tclasesEnSemana: " << curso1->getClasesEnSemana() << endl;
    cout << "\tCantidadGrupos: " << curso1->getCantidadGrupos() << endl << endl;

    cout << "Curso2:" << endl;
    cout << "\tid: " << curso2->getId() << endl;
    cout << "\t" << curso2->toString() << endl;
    cout << "\tcantidadHoras: " << curso2->getCantidadHoras() << endl;
    cout << "\tclasesEnSemana: " << curso2->getClasesEnSemana() << endl;
    cout << "\tCantidadGrupos: " << curso2->getCantidadGrupos() << endl << endl;

    cout << "Curso3:" << endl;
    cout << "\tid: " << curso3->getId() << endl;
    cout << "\t" << curso3->toString() << endl;
    cout << "\tcantidadHoras: " << curso3->getCantidadHoras() << endl;
    cout << "\tclasesEnSemana: " << curso3->getClasesEnSemana() << endl;
    cout << "\tCantidadGrupos: " << curso3->getCantidadGrupos() << endl << endl;

    if (curso1->igual(curso2)) {
        cout << "Curso1 es igual a Curso2." << endl;
    } else {
        cout << "Curso1 no es igual a Curso2." << endl;
    }

    if (curso1->igual(curso3)) {
        cout << "Curso1 es igual a Curso3." << endl;
    } else {
        cout << "Curso1 no es igual a Curso3." << endl;
    }

    if (curso2->igual(curso3)) {
        cout << "Curso2 es igual a Curso3." << endl;
    } else {
        cout << "Curso2 no es igual a Curso3." << endl;
    }
}
