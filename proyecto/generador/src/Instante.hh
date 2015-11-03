#ifndef CLASE_INSTANTE
#define CLASE_INSTANTE

#include <string>
#include "IInstante.hh"
#include "Dia.hh"


/**
 * @breif La clase Instante representa un instante en una semana. Los días se
 *        definen en el enum DIA, la horas están en el rango [0,23], los minutos
 *        en [0,59].
 */
class Instante : public IInstante
{
    private:
        /**
         * @breif El día del instante según el ENUM DIA.
         */
        Dia dia;

        /**
         * @breif La hora del instante. En caso que esté fuera del rango [0,23]
         *        se cambiará el día según corresponda. Si el día es indefinido,
         *        este no cambiará.
         */
        int hora;

        /**
         * @breif El minuto del instante. En caso que este fuera del rango
         *        [0,59] se cambiará la hora según corresponda.
         *        Para nuestro caso, los minutos serán 0 en todo caso.
         */
        int minuto;

        /**
         * @breif Chequea que el instante sea adecuado segun los rangos
         *        especificados para los minutos y las horas.
         * @return  True si es uin tiempo que cumple las restricciones.
         */
        bool chequearRestricciones(void);

        /**
         * @breif Devuelve un instante corregido a partir de otro instante,
         *        asegurandose que cumpla las resticciones de los rangos de
         *        dias, horas y minutos.
         *        En caso que el día no corresponda a ninguno, se asignará como
         *        INDEFINIDO.
         * @param  instante Instante que se desea corregir
         * @return          Un Instante dentro de los rangos adecuados.
         */
        Instante * getInstante(Instante * instante);

    public:

        virtual std::string toString(void);
        virtual bool igual(Instante * instante);
        virtual bool posterior(Instante * instante);
        virtual bool previo(Instante * instante);

        /**
         * @breif Constructor de la clase. Inicializa los valores.
         */
        Instante(Dia dia = INDEFINIDO, int hora = 0, int minuto = 0);

        /**
         * @breif Destructor de la clase.
         */
        virtual ~Instante();

        /**
         * @breif Método get para el día del instante.
         * @return El día del instante.
         */
        Dia getDia(void);

        /**
         * @breif Método set para el día del instante.
    hrs = std::to_string(this->getHora())         * @param dia El nuevo día del instante.
         */
        void setDia(Dia dia);

        /**
         * @breif Método get para la hora del instante.
         * @return La hora del instante.
         */
        int getHora(void);

        /**
         * @breif Método set para la hora del instante.
         * @param hora La nueva hora del instante.
         */
        void setHora(int hora);

        /**
         * @breif Método get para el minuto del instante.
         * @return El minuto del instante.
         */
        int getMinuto(void);

        /**
         * @breif Método set para el minuto del instante.
         * @param minuto El nuevo minuto del instante.
         */
        void setMinuto(int minuto);
};
#endif
