#include <iostream>
#include <stddef.h>
#include <cmath>
#include <sstream>

#include "Periodo.hh"
#include "IPeriodo.hh"

#include "Instante.hh"
#include "IInstante.hh"
#include "Dia.hh"
#include "Misc.hh"

/*******************************************************************************
 ** IMPLEMENTACION Periodo
 ******************************************************************************/

IInstante * Periodo::getInicio(void) {
    return this->inicio;
}

IInstante * Periodo::getFinal(void) {
    return this->fin;
}

bool Periodo::igual(IPeriodo *periodo) {

    return false;
}

bool Periodo::contieneInclusivo(IPeriodo *periodo) {

    return false;
}

bool Periodo::contieneExclusivo(IPeriodo *periodo) {

    return false;
}

bool Periodo::enInclusivo(IPeriodo *periodo) {

    return false;
}

bool Periodo::enExclusivo(IPeriodo *periodo) {

    return false;
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


/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

/**
 * @breif Main para probar la implementación de la clase.
 * @return  0.
 */
int testPeriodo(void) {
    using namespace std;


    return 0;
}
