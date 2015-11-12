#include <iostream>
#include <stddef.h>
#include <cmath>
#include <sstream>

#include "Instante.hh"
#include "IInstante.hh"
#include "Misc.hh"
#include "Dia.hh"

#include "Periodo.hh"
#include "IPeriodo.hh"

/*******************************************************************************
 ** IMPLEMENTACION Periodo
 ******************************************************************************/

IInstante *Periodo::getInicio(void) {
    return this->inicio;
}

IInstante *Periodo::getFin(void) {
    return this->fin;
}

bool Periodo::igual(IPeriodo *periodo) {
    bool a = this->getInicio()->igual(periodo->getInicio());
    bool b = this->getFin()->igual(periodo->getFin());
    return a && b;
}

bool Periodo::contieneInclusivo(IPeriodo *periodo) {
    bool a = this->getInicio()->previo(periodo->getInicio())
             || this->getInicio()->igual(periodo->getInicio());

    bool b = this->getFin()->posterior(periodo->getFin())
             || this->getFin()->igual(periodo->getFin());

    return a && b;
}

bool Periodo::contieneExclusivo(IPeriodo *periodo) {
    bool a = this->getInicio()->previo(periodo->getInicio());
    bool b = this->getFin()->posterior(periodo->getFin()) ;
    return a && b;
}

bool Periodo::enInclusivo(IPeriodo *periodo) {
    bool a = this->getInicio()->posterior(periodo->getInicio())
             || this->getInicio()->igual(periodo->getInicio());

    bool b = this->getFin()->previo(periodo->getFin())
             || this->getFin()->igual(periodo->getFin());

    return a && b;
}

bool Periodo::enExclusivo(IPeriodo *periodo) {
    bool a = this->getInicio()->posterior(periodo->getInicio());
    bool b = this->getFin()->previo(periodo->getFin());
    return a && b;
}

bool Periodo::igualDuracion(IPeriodo *periodo) {
    return false;
}

bool Periodo::mayorDuracion(IPeriodo *periodo) {
    return false;
}

bool Periodo::menorDuracion(IPeriodo *periodo) {
    return false;
}

bool Periodo::traslapa(IPeriodo *periodo) {
    return false;
}

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/
Periodo::Periodo(IInstante *inicio, IInstante *fin) {
    this->inicio = inicio;
    this->fin = fin;
}

void Periodo::setInicio(IInstante *inicio) {
    this->inicio = inicio;
}


void Periodo::setFin(IInstante *fin) {
    this->fin = fin;
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

int getDuracion(void) {
    
}

/**
 * @breif Main para probar la implementación de la clase.
 * @return  0.
 */
int testPeriodo(void) {
    using namespace std;

    IInstante *instante1 = new Instante(LUNES, 9, 0);
    IInstante *instante2 = new Instante(LUNES, 11, 0);
    Periodo *periodo1 = new Periodo(instante1, instante2);
    cout << "Creado periodo1 con:" << endl;
    cout << "\tInicio: " << periodo1->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo1->getFin()->toString() << endl;

    IInstante *instante3 = new Instante(LUNES, 9, 0);
    IInstante *instante4 = new Instante(LUNES, 11, 0);
    Periodo *periodo2 = new Periodo(instante3, instante4);
    cout << "Creado periodo2 con:" << endl;
    cout << "\tInicio: " << periodo2->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo2->getFin()->toString() << endl;

    if (periodo1->igual(periodo2)) {
        cout << "periodo1 y periodo2 son iguales" << endl;
    } else {
        cout << "periodo1 y periodo2 no son iguales" << endl;
    }

    return 0;
}
