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
 ** IMPLEMENTACION IINSTANTE
 ******************************************************************************/

IInstante * Periodo::getInicio(void) {
    return this->inicio;
}

IInstante * Periodo::getFinal(void) {
    return this->fin;
}

bool Periodo::igual(IPeriodo *periodo) {

}

bool Periodo::contieneInclusivo(IPeriodo *periodo) {

}

bool Periodo::contieneExclusivo(IPeriodo *periodo) {

}

bool Periodo::enInclusivo(IPeriodo *periodo) {

}


bool Periodo::enExclusivo(IPeriodo *periodo) {

}

bool Periodo::igualDuracion(IPeriodo *periodo) {

}

bool Periodo::mayorDuracion(IPeriodo *periodo) {

}

bool Periodo::menorDuracion(IPeriodo *periodo) {

}

bool Periodo::traslapa(IPeriodo *periodo) {

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
int testInstante(void) {
    using namespace std;
    return 0;
}
