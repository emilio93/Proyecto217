#ifndef CLASE_PERIODO
#define CLASE_PERIODO

/**
 * @breif La clase Periodo define un periodo delimitado dentro de una semana.
 *        Se define según un Instante inicial y otro final. En caso de que se
 *        utilize días indefinidos, deben estar en el inicio y en el fin.
 */
class Periodo : public IPeriodo {
    private:
        /**
         * @breif El inicio del Periodo.
         */
        Instante inicio;

        /**
         * @breif El fin del Periodo.
         */
        Instante fin;
    public:

        /**
         * @breif Constructor de la clase.
         */
        Periodo(Instante inicio, Instante fin);

        /**
         * @breif Método set para el Instante inicial del Periodo.
         * @param Instante El nuevo incio del Periodo.
         */
        void setInicio(Instante);

        /**
         * @breif Método set para el Instante final del Periodo.
         * @param Instante El nuevo fin del Periodo.
         */
        void setFin(Instante);

        virtual ~IPeriodo() {}

        virtual IInstante getInicio(void);

        virtual IInstante getFinal(void);

        virtual bolean igual(IPeriodo);

        virtual boolean contieneInclusivo(IPeriodo);

        virtual boolean contieneExclusivo(IPeriodo);

        virtual boolean enInclusivo(IPeriodo);

        virtual boolean enExclusivo(IPeriodo);

        virtual bolean igualDuracion(IPeriodo);

        virtual boolean mayorDuracion(IPeriodo);

        virtual boolean menorDuracion(IPeriodo);
};


#endif CLASE_PERIODO
