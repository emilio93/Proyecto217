#include <iostream>
#include <stddef.h>//This gets NULL

#include "Instante.hh"
#include "Dia.hh"

#include "Misc.hh"

/*******************************************************************************
 ** IMPLEMENTACION IINSTANTE
 ******************************************************************************/

virtual string Instante::toString(void) {
    string txt;
    txt = Dia::toString(this->dia) + this->hora + ":" + this->minutos;
    return txt;
}

virtual boolean Instante::igual(Instante) {
    ;
}

virtual boolean Instante::posterior(Instante) {
    ;
}

virtual boolean Instante::previo(Instante) {
    ;
}

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Instante::Instante() {
    this->setMinuto(0);
}

virtual Instante::~IPeriodo() {
    ;
}

int Instante::getDia(void) { return this->dia; }

void Instante::setDia(Dia dia) { this->dia = dia; }

int Instante::getHora(void) {return this->hora; }

void Instante::setHora(int hora) { this->hora = hora; }

int Instante::getMinuto(void) { return this->minuto; }

void Instante::setMinuto(int minuto) { this->minuto = minuto; }

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

boolean Instante::chequearRestricciones(void) {
    boolean correcto = false;
    if(Misc::enRango<int>(this->minuto, 0, 59) && Misc::enRango<int>(this->hora, 0, 23)) {
           correcto = true;
    }
    return correcto;
}

Instante getInstante(Instante instante) {
    Instante corregido = new Instante();
}
