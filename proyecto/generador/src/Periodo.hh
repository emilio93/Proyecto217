#ifndef CLASE_PERIODO
#define CLASE_PERIODO

#include <vector>

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

    public:
        //! El constructor de la clase.
        /*!
         * Asigna los valores de instante inicial e intante final respectivamente.
         * Si el instante final es previo al inicial, se intercambian.
         * Si un dia es INDEFINIDO y el otro no, asigna ambos a INDEFINIDO.
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
        virtual int getDuracion(void);
        virtual bool igualDuracion(IPeriodo *periodo);
        virtual bool mayorDuracion(IPeriodo *periodo);
        virtual bool menorDuracion(IPeriodo *periodo);
        virtual bool traslapa(IPeriodo *periodo);
        virtual std::vector<IPeriodo*> *restar(IPeriodo *total, IPeriodo *resta);
};

#endif
