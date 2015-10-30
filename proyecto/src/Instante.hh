#ifndef CLASE_INSTANTE
#define CLASE_INSTANTE

#include <string>

#include Dia.hh

/**
 * @breif La clase Instante representa un instante en una semana. Los días se
 *        definen en el enum DIA, la horas están en el rango [0,23], los minutos
 *        en [0,59].
 */
class Instante : public IInstante {
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

    public:

        /**
         * @breif Constructor de la clase.
         */
        Instante();

        virtual ~IPeriodo() {}

        /**
         * @breif Método get para el día del instante.
         * @return El día del instante.
         */
        int getDia(void);

        /**
         * @breif Método set para el día del instante.
         * @param dia El nuevo día del instante.
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

        virtual string toString(void);

        virtual boolean igual(Instante);

        virtual boolean posterior(Instante);

        virtual boolean previo(Instante);
};
#endif
