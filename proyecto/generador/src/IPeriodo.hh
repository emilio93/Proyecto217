#ifndef INTERFACE_PERIODO
#define INTERFACE_PERIODO

#include "IInstante.hh"

//! Representación de un periodo continuo.
/*!
 * Este perido puede indicar su Instante de inicio así como su final. Además
 * tiene distintas maneras de compararse con otros periodos. Si se requiere
 * otro tipo de comparación este debe realizarse mediante los métodos de
 * comparación que se especifican en IInstante.
 */
class IPeriodo {
    public:
        //! Destructor.
        /*!
         * Destructor por defecto.
         */
        virtual ~IPeriodo(void) {;}

        //! Devuelve el Instante inicial.
        /*!
         * Devuelve el Instante inicial del periodo. Se debe asegurar que
         * el instante inicial previo al final.
         * @return El instante inicial del periodo.
         */
        virtual IInstante *getInicio(void) = 0;

        //! Devuelve el instante final.
        /*!
         * Devuelve el Instante final del periodo. Se debe asegurar que
         * el instante final es posterior al inicial.
         * @return El instante final del periodo.
         */
        virtual IInstante *getFin(void) = 0;

        //! Indica la igualdad de dos periodos.
        /*!
         * Indica si dos periodos son iguales, esto es, que sus instantes
         * iniciales y finales sean iguales.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si los periodos son iguales, false en caso contrario.
         */
        virtual bool igual(IPeriodo *periodo) = 0;

        //! Indica si el periodo contiene a otro.
        /*!
         * Indica si el periodo contiene o es el mismo periodo que el periodo
         * con el cual se está comparando. Puede suceder que sus inicios y/o sus
         * finales sean iguales.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si contiene el otro periodo.
         */
        virtual bool contieneInclusivo(IPeriodo *periodo) = 0;

        //! Indica si el periodo contiene a otro.
        /*!
         * Indica si el periodo contiene estrictamente el periodo con el cual
         * se está comparando. No puede suceder que sus inicios ni sus finales
         * sean iguales.
         * @param periodo Periodo con el cual se compara.
         * @return True si contiene el otro periodo.
         */
        virtual bool contieneExclusivo(IPeriodo *periodo) = 0;

        //! Indica si el periodo está contenido dentro de otro.
        /*!
         * Indica si un periodo es el mismo, o está contenido en el periodo con
         * el cual se está comparando.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si está en otro periodo, false en caso contrario.
         */
        virtual bool enInclusivo(IPeriodo *periodo) = 0;

        //! Indica si el periodo está contenido dentro de otro.
        /*!
         * Indica si un periodo está contenido en el periodo con el cual se está
         * comparando.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si está en otro periodo, false en caso contrario.
         */
        virtual bool enExclusivo(IPeriodo *periodo) = 0;

        //! Obtiene la duración del IPeriodo.
        /*!
         * Obtiene la duración IPeriodo.
         * @return  La duración del IPeriodo.
         */
        virtual int getDuracion(void) = 0;

        //! Indica si dos periodos duran lo mismo.
        /*!
         * Indica si dos periodos son iguales en duración, esto es, que
         *        la diferencia de sus instantes inicial y final, sea iguales.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si duran lo mismo, false en caso contrario.
         */
        virtual bool igualDuracion(IPeriodo *periodo) = 0;

        //! Indica si un periodo dura más que otro.
        /*!
         * Indica si un periodo es mayor en duración con
         * respecto al otro periodo.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si el perido dura mas, false en caso contrario.
         */
        virtual bool mayorDuracion(IPeriodo *periodo) = 0;

        //! Indica si un periodo dura menos que otro.
        /*!
         * Indica si un periodo es menor en duración con
         * respecto al otro periodo.
         * @param periodo Periodo con el cual se está comparando.
         * @return True si el perido dura menos, false en caso contrario.
         */
        virtual bool menorDuracion(IPeriodo *periodo) = 0;

        //! Indica si dos periodos tienen un sub-periodo en común.
        /*!
         * Indica si dos periodos tienen un sub-periodo en común. Si el
         * intante final del primero, es el inicial del segundo, no hay
         * traslape, esto es, la duración del sub-periodo debe ser mayor
         * a 0.
         * @param  periodo Periodo contra el cual se verifica si hay traslape.
         * @return True en caso que haya traslape, false en caso
         * contrario.
         */
        virtual bool traslapa(IPeriodo *periodo) = 0;
};

#endif
