#include <iostream>
#include <stddef.h>
#include <cmath>
#include <sstream>

#include "Instante.hh"
#include "IInstante.hh"
#include "Dia.hh"

#include "Misc.hh"

/*******************************************************************************
 ** IMPLEMENTACION IINSTANTE
 ******************************************************************************/

std::string Instante::toString(void) {
    std::string txt, hrs, mns; // texto horas minutos
    //Supongase un martes a las nueve y ocho de la mañana, se devuelve
    //martes 9:08
    hrs = Misc::to_string(this->getHora());
    mns = Misc::to_string(this->getMinuto());
    mns = this->getMinuto() < 10? "0" + mns: mns;

    std::string dia = diaToString(this->getDia());

    txt = dia + " " + hrs + ":" + mns;
    return txt;
}

bool Instante::igual(IInstante * instante) {
    bool resultado = false;
    Instante * inst = dynamic_cast<Instante*>(instante);

    //Todo debe ser igual, es la única manera que dos instantes sean iguales.
    if (this->getDia() == inst->getDia() &&
        this->getHora() == inst->getHora() &&
        this->getMinuto() == inst->getMinuto()) {
        resultado = true;
    }
    return resultado;
}

bool Instante::posterior(IInstante * instante) {
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

bool Instante::previo(IInstante * instante) {
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

//Instante::Instante(Dia dia = INDEFINIDO, int hora = 0, int minuto = 0)
Instante::Instante(Dia dia, int hora, int minuto) {
    this->setDia(dia);
    this->setHora(hora);
    this->setMinuto(minuto);
    this->getInstante();
}

Dia Instante::getDia(void) { return this->dia; }

void Instante::setDia(Dia dia) { this->dia = dia; }

int Instante::getHora(void) {return this->hora; }

void Instante::setHora(int hora) { this->hora = std::abs(hora); }

int Instante::getMinuto(void) { return this->minuto; }

void Instante::setMinuto(int minuto) { this->minuto = std::abs(minuto); }

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

bool Instante::chequearRestricciones(void) {
    return (Misc::enRango<int>(diaToInt(this->dia), 0, 7 ) &&
            Misc::enRango<int>(this->minuto, 0, 59) &&
            Misc::enRango<int>(this->hora, 0, 23)) ?
                true : false;
}

Instante * Instante::getInstante(IInstante * instante) {
    Instante * corregido;
    Instante * inst = dynamic_cast<Instante*>(instante);

    if (inst->chequearRestricciones()) {
        return inst;
    } else {
        corregido = new Instante(inst->getDia(), inst->getHora(), inst->getMinuto());
        if (!Misc::enRango(diaToInt(inst->getDia()), 0, 7)) {
            corregido->setDia(INDEFINIDO);
        }

        if (!Misc::enRango(inst->getMinuto(), 0, 59)) {
            corregido->setMinuto(inst->getMinuto() - 60);
            corregido->setHora(inst->getHora() + 1);
        }

        if (!Misc::enRango(inst->getHora(), 0, 23)) {
            corregido->setHora(inst->getHora() - 24);
            if (inst->getDia() == DOMINGO) {
                corregido->setDia(LUNES);
            } else if (inst->getDia() == INDEFINIDO){
                corregido->setDia(INDEFINIDO);
            } else {
                corregido->setDia(intToDia(diaToInt(inst->getDia()) + 1));
            }
        }

        return this->getInstante(corregido);
    }
}

void Instante::getInstante(void) {

    if (this->chequearRestricciones()) {
        return;
    } else {

        if (!Misc::enRango(diaToInt(this->getDia()), 0, 7)) {
            this->setDia(INDEFINIDO);
        }

        if (!Misc::enRango(this->getMinuto(), 0, 59)) {
            this->setMinuto(this->getMinuto() - 60);
            this->setHora(this->getHora() + 1);
        }

        if (!Misc::enRango(this->getHora(), 0, 23)) {
            this->setHora(this->getHora() - 24);
            if (this->getDia() == DOMINGO) {
                this->setDia(LUNES);
            } else if (this->getDia() == INDEFINIDO){
                this->setDia(INDEFINIDO);
            } else {
                this->setDia(intToDia(diaToInt(this->getDia()) + 1));
            }
        }
        return this->getInstante();
    }
}

/**
 * @breif Main para probar la implementación de la clase.
 * @return  0.
 */
int main(void) {

    std::string resultado;

    IInstante * inst1 = new Instante(LUNES, 7, 00);
    std::cout << "Instante 1: ";
    std::cout << inst1->toString() << std::endl;

    IInstante * inst2 = new Instante(LUNES, 7, 00);
    std::cout << "Instante 2: ";
    std::cout << inst2->toString() << std::endl;

    IInstante * inst3 = new Instante(MARTES, 7, 00);
    std::cout << "Instante 3: ";
    std::cout << inst3->toString() << std::endl;

    IInstante * inst4 = new Instante(MIERCOLES, 7, 00);
    std::cout << "Instante 4: ";
    std::cout << inst4->toString() << std::endl;

    IInstante * inst5 = new Instante(MIERCOLES, 9, 00);
    std::cout << "Instante 5: ";
    std::cout << inst5->toString() << std::endl;

    IInstante * inst6 = new Instante(MIERCOLES, 9, 30);
    std::cout << "Instante 6: ";
    std::cout << inst6->toString() << std::endl;

    std::cout << std::endl;

    std::cout << "Instante1 es igual a Instante2? ";
    resultado = inst1->igual(inst2)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante1 es igual a Instante3? ";
    resultado = inst1->igual(inst3)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante5 es igual a Instante6? ";
    resultado = inst5->igual(inst6)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << std::endl;

    std::cout << "Instante1 es previo a Instante2? ";
    resultado = inst1->previo(inst2)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante2 es previo a Instante1? ";
    resultado = inst2->previo(inst1)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante2 es previo a Instante3? ";
    resultado = inst2->previo(inst3)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante3 es previo a Instante2? ";
    resultado = inst3->previo(inst2)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante4 es previo a Instante5? ";
    resultado = inst4->previo(inst5)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante5 es previo a Instante6? ";
    resultado = inst5->previo(inst6)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante6 es previo a Instante5? ";
    resultado = inst6->previo(inst5)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << std::endl;

    std::cout << "Instante1 es posterior a Instante2? ";
    resultado = inst1->posterior(inst2)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante2 es posterior a Instante1? ";
    resultado = inst2->posterior(inst1)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante2 es posterior a Instante3? ";
    resultado = inst2->posterior(inst3)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante3 es posterior a Instante2? ";
    resultado = inst3->posterior(inst2)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante4 es posterior a Instante5? ";
    resultado = inst4->posterior(inst5)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante5 es posterior a Instante6? ";
    resultado = inst5->posterior(inst6)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << "Instante6 es posterior a Instante5? ";
    resultado = inst6->posterior(inst5)? "Si": "No";
    std::cout << resultado << std::endl;

    std::cout << std::endl << std::endl;

    IInstante * inst7 = new Instante(INDEFINIDO, 25, 68);
    std::cout << "Instante 7 seteado con (INDEFINIDO, 25, 68)" << std::endl;
    std::cout << "Instante 7: ";
    std::cout << inst7->toString() << std::endl;

    IInstante * inst8 = new Instante(LUNES, 25, 68);
    std::cout << "Instante 8 seteado con (LUNES, 25, 68)" << std::endl;
    std::cout << "Instante 8: ";
    std::cout << inst8->toString() << std::endl;

    IInstante * inst9 = new Instante(DOMINGO, 25, 68);
    std::cout << "Instante 9 seteado con (DOMINGO, 25, 68)" << std::endl;
    std::cout << "Instante 9: ";
    std::cout << inst9->toString() << std::endl;

    IInstante * inst10 = new Instante(SABADO, 75, 150);
    std::cout << "Instante 10 seteado con (SABADO, 75, 150)" << std::endl;
    std::cout << "Instante 10: ";
    std::cout << inst10->toString() << std::endl;

    return 0;
}
