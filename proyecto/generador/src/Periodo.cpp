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

int Periodo::getDuracion(void) {
    int duracion = 0;

    Instante *inst1 = Instante::toInstante(this->getInicio());
    Instante *inst2 = Instante::toInstante(this->getFin());

    duracion =+ inst2->getMinuto() - inst1->getMinuto();

    int difHoras = inst2->getHora() - inst1->getHora();
    duracion += 60 * (difHoras);

    int difDias = diaToInt(inst2->getDia()) - diaToInt(inst1->getDia());
    duracion += 60 * 24 * (difDias);

    return duracion;
}

bool Periodo::igualDuracion(IPeriodo *periodo) {
    return this->getDuracion() == periodo->getDuracion();
}

bool Periodo::mayorDuracion(IPeriodo *periodo) {
    return this->getDuracion() > periodo->getDuracion();
}

bool Periodo::menorDuracion(IPeriodo *periodo) {
    return this->getDuracion() < periodo->getDuracion();
}

bool Periodo::traslapa(IPeriodo *periodo) {
    bool a = this->contieneInclusivo(periodo);
    bool b = this->enInclusivo(periodo);
    bool c = this->getInicio()->previo(periodo->getFin());
    bool d = this->getFin()->posterior(periodo->getInicio());
    return a || b || c || d;
}

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/
Periodo::Periodo(IInstante *inicio, IInstante *fin) {
    if (inicio->posterior(fin)) {
        IInstante *temp = inicio;
        inicio = fin;
        fin = temp;
    }
    if (!(Instante::toInstante(inicio)->getDia() == INDEFINIDO)
     != !(Instante::toInstante(fin)->getDia() == INDEFINIDO)) {
        Instante::toInstante(inicio)->setDia(INDEFINIDO);
        Instante::toInstante(fin)->setDia(INDEFINIDO);
    }

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




void hacerTest(bool test, std::string str) {
    using namespace std;
    if (test) {
        cout << "SI: ";
    } else {
        cout << "NO: ";
    }
    cout << str << endl;
}

/**
 * @breif Main para probar la implementación de la clase.
 */
void testPeriodo(void) {
    using namespace std;

    Periodo *periodo1 = new Periodo(new Instante(LUNES, 7, 0), new Instante(LUNES, 9, 0));
    cout << "Creado periodo1 con:" << endl;
    cout << "\tInicio: " << periodo1->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo1->getFin()->toString() << endl;
    cout << "\tDuración: " << periodo1->getDuracion() << endl;

    Periodo *periodo2 = new Periodo(new Instante(LUNES, 7, 0), new Instante(LUNES, 9, 0));
    cout << "Creado periodo2 con:" << endl;
    cout << "\tInicio: " << periodo2->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo2->getFin()->toString() << endl;
    cout << "\tDuración: " << periodo2->getDuracion() << endl;

    Periodo *periodo3 = new Periodo(new Instante(LUNES, 7, 0), new Instante(LUNES, 10, 0));
    cout << "Creado periodo3 con:" << endl;
    cout << "\tInicio: " << periodo3->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo3->getFin()->toString() << endl;
    cout << "\tDuración: " << periodo3->getDuracion() << endl;

    Periodo *periodo4 = new Periodo(new Instante(LUNES, 9, 0), new Instante(MARTES, 11, 0));
    cout << "Creado periodo4 con:" << endl;
    cout << "\tInicio: " << periodo4->getInicio()->toString() << endl;
    cout << "\tFin: " << periodo4->getFin()->toString() << endl;
    cout << "\tDuración: " << periodo4->getDuracion() << endl;

    hacerTest(periodo1->igual(periodo2), "periodo1 y periodo2 son iguales");
    hacerTest(periodo1->traslapa(periodo2), "periodo1 y periodo2 traslapan");
    hacerTest(periodo1->contieneInclusivo(periodo2), "periodo1 y periodo2 contiene inclusivo");
    hacerTest(periodo1->contieneExclusivo(periodo2), "periodo1 y periodo2 contiene exclusivo");
    hacerTest(periodo1->igual(periodo3), "periodo1 y periodo3 son iguales");

}
