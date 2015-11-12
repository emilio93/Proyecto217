#ifndef CLASE_PERIODO
#define CLASE_PERIODO

#include "IPeriodo.hh"
#include "IInstante.hh"

//! Un período delimitado por instantes inicial y final.
/*!
 * La clase Periodo define un periodo delimitado dentro de una semana.
 * Se define según un Instante inicial y otro final. En caso de que se
 * utilize días indefinidos, deben estar en el inicio y en el fin.
 */
class Periodo : public IPeriodo {
    private:
        //! Inicio del periodo.
        /*!
         * El inicio del periodo.
         */
        IInstante *inicio;

        //! El fin del periodo.
        /*!
         * El fin del periodo.
         */
        IInstante *fin;

        //! Obtiene la duración en horas del Periodo.
        /*!
         * Obtiene la duración en horas del Periodo. En caso de que el periodo dure
         * varios días, se obtiene igualmente las horas que transcurren del instante
         * inicial al final.
         * @return  La duración en horas del Periodo.
         */
        int getDuracion(void);

    public:
        //! El constructor de la clase.
        /*!
         * Asigna los valores de instante inicial e intante final respectivamente.
         * @param inicio Instante inicial.
         * @param fin Instante final.
         */
        Periodo(IInstante *inicio, IInstante *fin);

        //! Método set para el Instante inicial del Periodo.
        /*!
         * Método set para el Instante inicial del Periodo.
         * @param instante El nuevo incio del Periodo.
         */
        void setInicio(IInstante *instante);

        //! Método set para el Instante final del Periodo.
        /*!
         * Método set para el Instante final del Periodo.
         * @param instante El nuevo fin del Periodo.
         */
        void setFin(IInstante *instante);

        virtual IInstante *getInicio(void);
        virtual IInstante *getFin(void);
        virtual bool igual(IPeriodo *periodo);
        virtual bool contieneInclusivo(IPeriodo *periodo);
        virtual bool contieneExclusivo(IPeriodo *periodo);
        virtual bool enInclusivo(IPeriodo *periodo);
        virtual bool enExclusivo(IPeriodo *periodo);
        virtual bool igualDuracion(IPeriodo *periodo);
        virtual bool mayorDuracion(IPeriodo *periodo);
        virtual bool menorDuracion(IPeriodo *periodo);
        virtual bool traslapa(IPeriodo *periodo);
};

#endif
