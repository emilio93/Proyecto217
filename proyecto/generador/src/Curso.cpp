#include <iostream>
#include <stddef.h>
#include <string>
#include <list>

#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Curso::Curso(int id, int cantidadHoras, int clasesEnSemana, int cantidadGrupos, std::string nombre, std::string sigla) {
    this->setId(id);
    this->setCantidadHoras(cantidadHoras);
    this->setClasesEnSemana(clasesEnSemana);
    this->setCantidadGrupos(cantidadGrupos);
    this->setNombre(nombre);
    this->setSigla(sigla);
}

int Curso::getId(void) { return this->id; }

void Curso::setId(int id) { this->id = id; }

int Curso::getCantidadHoras(void) { return this->cantidadHoras; }

void Curso::setCantidadHoras(int cantidadHoras) { this->cantidadHoras = cantidadHoras; }

int Curso::getClasesEnSemana(void) { return this->clasesEnSemana; }

void Curso::setClasesEnSemana(int clasesEnSemana) { this->clasesEnSemana = clasesEnSemana; }

int Curso::getCantidadGrupos(void) { return this->cantidadGrupos; }

void Curso::setCantidadGrupos(int cantidadGrupos) { this->cantidadGrupos = cantidadGrupos; }

std::string Curso::getNombre(void) { return this->nombre; }

void Curso::setNombre(std::string nombre) { this->nombre = nombre; }

std::string Curso::getSigla(void) { return this->sigla; }

void Curso::setSigla(std::string sigla) { this->sigla = sigla; }

std::string Curso::toString(void) {
    return this->getNombre() + " - " + this->getSigla();
}

std::list<Grupo*> * Curso::crearGrupos(void) {
    std::list<Grupo*> * grupos = new std::list<Grupo*>();
    //código
    return grupos;
}

 /*******************************************************************************
  ** MÉTODOS PRIVADOS
  ******************************************************************************/

//NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 * @return  0.
 */
int main(void) {

    Curso * curso1 = new Curso(1, 5, 2, 1, "Circuitos Lineles I", "IE0209");
    std::cout << curso1->toString() << " creado." << std::endl;
    std::cout << "\tid: " << curso1->getId() << std::endl;
    std::cout << "\tcantidadHoras: " << curso1->getCantidadHoras() << std::endl;
    std::cout << "\tclasesEnSemana: " << curso1->getClasesEnSemana() << std::endl;
    std::cout << "\tCantidadGrupos: " << curso1->getCantidadGrupos() << std::endl;

    return 0;
}
