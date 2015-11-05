#ifndef INTERFACE_PERIODO
#define INTERFACE_PERIODO

#include "IInstante.hh"

/**
 * @breif Representación de un periodo continuo.
 *
 * Este perido puede indicar su Instante de inicio así como su final. Además
 * tiene distintas maneras de compararse con otros periodos. Si se requiere
 * otro tipo de comparación este debe realizarse mediante los métodos de
 * comparación que se especifican en IInstante.
 */
class IPeriodo {
    public:
        /**
         * @breif Destructor por defecto.
         */
        virtual ~IPeriodo() {}

        /**
         * @breif Devuelve el Instante inicial del periodo. Se debe asegurar que
         *        el instante inicial previo al final.
         * @return  El instante inicial del periodo.
         */
        virtual IInstante * getInicio(void) = 0;

        /**
         * @breif Devuelve el Instante final del periodo. Se debe asegurar que
         *        el instante final es posterior al inicial.
         * @return  El instante final del periodo.
         */
        virtual IInstante * getFinal(void) = 0;

        /**
         * @breif Indica si dos periodos son iguales, esto es, que
         *        sus instantes iniciales y finales sean iguales.
         */
        virtual bool igual(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo contiene o es el mismo periodo
         *        que el periodo con el cual se está comparando.
         */
        virtual bool contieneInclusivo(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo contiene el periodo con
         *        el cual se está comparando.
         */
        virtual bool contieneExclusivo(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo es el mismo, o está contenido
         *        en el periodo con el cual se está comparando.
         */
        virtual bool enInclusivo(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo está contenido
         *        en el periodo con el cual se está comparando.
         */
        virtual bool enExclusivo(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si dos periodos son iguales en duración, esto es, que
         *        la diferencia de sus instantes inicial y final, sea iguales.
         */
        virtual bool igualDuracion(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo es mayor en duración con
         *        respecto al otro periodo.
         */
        virtual bool mayorDuracion(IPeriodo * periodo) = 0;

        /**
         * @breif Indica si un periodo es menor en duración con
         *        respecto al otro periodo.
         */
        virtual bool menorDuracion(IPeriodo * periodo) = 0;

        /**
         *  @breif Indica si dos periodos tienen un sub-periodo en común. Si el
         *         intante final del primero, es el inicial del segundo, no hay
         *         traslape, esto es, la duración del sub-periodo debe ser mayor a
         *         0.
         * @param  IPeriodo Periodo contra el cual se verifica si hay traslape.
         * @return          Treu en caso que haya traslape, false en caso contrario.
         */
        virtual bool traslapa(IPeriodo * periodo) = 0;
};

#endif
