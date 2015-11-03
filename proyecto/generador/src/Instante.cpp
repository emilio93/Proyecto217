#include <iostream>
#include <stddef.h>
#include <cmath>

#include "Instante.hh"
#include "Dia.hh"

#include "Misc.hh"

/*******************************************************************************
 ** IMPLEMENTACION IINSTANTE
 ******************************************************************************/

virtual string Instante::toString(void) {
    string txt, hrs, mns; // texto horas minutos
    //Supongase un martes a las nueve y ocho de la mañana, se devuelve
    //martes 9:08
    hrs = std::to_string(this->getHora());
    mns = std::to_string(this->getMinuto());
    mns = this->getMinuto() < 10? "0" + mns: mns;
    txt = diatoString(this->getDia()) + " " + this->getHora() + ":" + mins;
    return txt;
}

virtual bool Instante::igual(Instante * instante) {
    bool resultado = false;

    //Todo debe ser igual, es la única manera que dos instantes sean iguales.
    if (this->getDia() == instante->getDia() &&
        this->getHora() == instante->getHora() &&
        this->getMinuto() == instante->getMinuto()) {
        resultado = true;
    }
    return resultado;
}

virtual bool Instante::posterior(Instante * instante) {
    bool resultado = false;

    Instante * primero = this->getInstante(this);
    Instante * segundo = this->getInstante(instante);

    /*
        Para que un instante sea posterior debe darse alguno se estos casos:
            -que el primer día sea posterior, siempre y cuando ninguno sea
                INDEFINIDO.
            -que sean el mismo día, y que la hora del primero sea posterior.
            -que sean el mismo día, misma hora, y que los minutos del primero
                sea posterior.
     */
    if ((primero->getDia() != INDEFINIDO && segundo->getDia() != INDEFINIDO)
    || (primero->getDia() == INDEFINIDO && segundo->getDia() == INDEFINIDO)) {
        if (primero->getDia() > segundo->getDia()) {
            resultado = true;
        } else if (primero->getDia() == segundo->getDia()) {
            if (primero->getHora() > segundo->getHora()) {
                resultado = true;
            } else if (primero->getHora() == segundo->getHora()) {
                if (primero->getMinuto() > segundo->getMinuto()) {
                    resultado = true;
                }
            }
        }
    }

    return resultado;
}

virtual bool Instante::previo(Instante * instante) {
    bool resultado = false;

    Instante * primero = this->getInstante(this);
    Instante * segundo = this->getInstante(instante);

    /*
        Para que un instante sea previo debe darse alguno se estos casos:
            -que el primer día sea previo, siempre y cuando ninguno sea
                INDEFINIDO.
            -que sean el mismo día, y que la hora del primero sea previa.
            -que sean el mismo día, misma hora, y que los minutos del primero
                sea previo.
     */
     if ((primero->getDia() != INDEFINIDO && segundo->getDia() != INDEFINIDO)
     || (primero->getDia() == INDEFINIDO && segundo->getDia() == INDEFINIDO)) {
         if (primero->getDia() < segundo->getDia()) {
             resultado = true;
         } else if (primero->getDia() == segundo->getDia()) {
             if (primero->getHora() < segundo->getHora()) {
                 resultado = true;
             } else if (primero->getHora() == segundo->getHora()) {
                 if (primero->getMinuto() < segundo->getMinuto()) {
                     resultado = true;
                 }
             }
         }
     }

    return resultado;
}

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Instante::Instante(Dia dia = INDEFINIDO, int hora = 0, int minuto = 0) {
    this->setDia(dia);
    this->setHora(hora);
    this->setMinuto(minuto);
}

virtual Instante::~IPeriodo() { ; }

int Instante::getDia(void) { return this->dia; }

void Instante::setDia(Dia dia) { this->dia = std::abs(dia); }

int Instante::getHora(void) {return this->hora; }

void Instante::setHora(int hora) { this->hora = std::abs(hora); }

int Instante::getMinuto(void) { return this->minuto; }

void Instante::setMinuto(int minuto) { this->minuto = std::abs(minuto); }

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

bool Instante::chequearRestricciones(void) {
    return (Misc::enRango<int>(this->dia, 0, 7 ) &&
            Misc::enRango<int>(this->minuto, 0, 59) &&
            Misc::enRango<int>(this->hora, 0, 23)) ?
                true : false;
}

Instante * Instante::getInstante(Instante * instante) {
    Instante * corregido;
    if (instante->chequearRestricciones()) {
        return instante;
    } else {
        corregido = new Instante();
        if (!Misc::enRango(instante->getDia(), 0, 7)) {
            corregido->setDia(INDEFINIDO);
        }

        if (!Misc::enRango(instante->getMinuto(), 0, 59)) {
            corregido->setMinuto(instante->getMinuto() - 60);
            corregido->setHora(instante->getHora() + 1);
        }
        if (!Misc::enRango(instante->getHora())) {
            corregido->setHora(instante->getHora() - 24);
            if (instante->getDia() == DOMINGO) {
                corregido->setDia(LUNES);
            } else if (instante->getDia() == INDEFINIDO){
                corregido->setDia(INDEFINIDO);
            } else {
                corregido->setDia(instante->getDia() + 1);
            }
        }

        return this->getInstante(corregido);
    }
}
