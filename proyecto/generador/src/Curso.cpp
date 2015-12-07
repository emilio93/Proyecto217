/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <algorithm>
#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"

/*******************************************************************************
 ** ATRIBUTOS ESTÁTICOS PRIVADOS
 ******************************************************************************/

int Curso::ID = 0;
int Curso::CANTIDAD_HORAS = 0;
int Curso::CLASES_EN_SEMANA = 0;
int Curso::CANTIDAD_GRUPOS = 0;
Bloque *null = NULL;
Bloque &Curso::BLOQUE = *null;
std::string Curso::NOMBRE = "";
std::string Curso::SIGLA = "";

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Curso::Curso(int id, int cantidadHoras, int clasesEnSemana,
    int cantidadGrupos, Bloque &bloque, std::string nombre,
    std::string sigla) {
    this->setId(id);
    this->setCantidadHoras(cantidadHoras);
    this->setClasesEnSemana(clasesEnSemana);
    this->setCantidadGrupos(cantidadGrupos);
    this->setBloques(new std::vector<Bloque>());
    this->agregarBloque(bloque);
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

std::vector<Bloque> *Curso::getBloques(void) {
    return this->bloques;
}

void Curso::setBloques(std::vector<Bloque> *bloques) {
    this->bloques = bloques;
}

void Curso::agregarBloque(Bloque &bloque) {
        this->bloques->push_back(bloque);
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

std::vector<Grupo> *Curso::crearGrupos(void) {
    std::vector<Grupo> *grupos = new std::vector<Grupo>();
    // código
    // TODO(emilio): implementar
    // código
    return grupos;
}

std::vector<Profesor> *Curso::getProfesores(void) {
    return Serializacion::getProfesores(*this);
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
 * @brief Main para probar la implementación de la clase.
 */
void testCurso(void) {
    using std::cout;
    using std::endl;
    using std::string;


    string c1 = "Circuitos Lineles I";
    string s1 = "IE0209";

    string c2 = "Circuitos Lineles II";
    string s2 = "IE0309";

    int id1 = 1;
    int id2 = 2;
    int id3 = 3;

    int canH1 = 4;
    int canH2 = 5;
    int canH3 = 6;

    int ceS1 = 2;
    int ceS2 = 2;
    int ceS3 = 1;

    int cG1 = 4;
    int cG2 = 3;
    int cG3 = 2;

    Plan plann = Plan();
    Plan &plan = plann;

    int idB = 1;
    int semB = 1;
    Bloque bloque = Bloque(idB, plan, semB);

    Curso *curso1 = new Curso(id1, canH1, ceS1, cG1, bloque, c1, s1);
    cout << curso1->toString() << " creado." << endl;

    Curso *curso2 = new Curso(id2, canH2, ceS2, cG2, bloque, c1, s1);
    cout << curso2->toString() << " creado." << endl;

    Curso *curso3 = new Curso(id3, canH3, ceS3, cG3, bloque, c2, s2);
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
