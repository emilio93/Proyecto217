#ifndef CLASE_PERIODO
#define CLASE_PERIODO

//! Un período delimitado por instantes inicial y final.
/**
 * La clase Periodo define un periodo delimitado dentro de una semana.
 * Se define según un Instante inicial y otro final. En caso de que se
 * utilize días indefinidos, deben estar en el inicio y en el fin.
 */
class Periodo : public IPeriodo {
    private:
        /**
         * @breif El inicio del Periodo.
         */
        Instante *inicio;

        /**
         * @breif El fin del Periodo.
         */
        Instante *fin;

    public:
        /**
         * @breif Constructor de la clase.
         */
        Periodo(Instante *inicio, Instante *fin);

        /**
         * @breif Método set para el Instante inicial del Periodo.
         * @param Instante El nuevo incio del Periodo.
         */
        void setInicio(Instante *instante);

        /**
         * @breif Método set para el Instante final del Periodo.
         * @param Instante El nuevo fin del Periodo.
         */
        void setFin(Instante *instante);

        virtual IInstante *getInicio(void);

        virtual IInstante *getFinal(void);

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
