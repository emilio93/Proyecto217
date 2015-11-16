#ifndef CLASE_INSTANTE
#define CLASE_INSTANTE

#include <string>
#include "IInstante.hh"
#include "Dia.hh"

//! Un instante dentro de una semana.
/*!
 * La clase Instante representa un instante en una semana. Tiene alcanze de dias,
 * horas y minutos. Los días se definen en el enum DIA, la horas están en el rango
 * [0,23], los minutos en [0,59].
 */
class Instante : public IInstante
{
    private:
        //! El día del instante.
        /*!
         * El día del instante según el ENUM DIA.
         */
        Dia dia;

        //! La Hora del instante.
        /*!
         * La hora del instante. En caso que esté fuera del rango [0,23]
         * se cambiará el día según corresponda. Si el día es indefinido,
         * este no cambiará.
         */
        int hora;

        //! El minuto del instante.
        /*!
         * El minuto del instante. En caso que este fuera del rango
         * [0,59] se cambiará la hora según corresponda.
         * Para nuestro caso, los minutos serán 0 en todo caso.
         */
        int minuto;

        //! Chequea que el instante esté en formato correcto.
        /*!
         * Chequea que el instante sea adecuado segun los rangos
         * especificados para los minutos y las horas.
         * @return True si es uin tiempo que cumple las restricciones.
         */
        bool chequearRestricciones(void);

        //! Devuelve un instante equivalente con formato correcto.
        /*!
         * Devuelve un instante corregido a partir de otro instante,
         * asegurandose que cumpla las resticciones de los rangos de
         * dias, horas y minutos.
         * En caso que el día no corresponda a ninguno, se asignará como
         * INDEFINIDO.
         * @param instante Instante que se desea corregir
         * @return Un Instante dentro de los rangos adecuados.
         */
        Instante * getInstante(IInstante *instante);

        //! Devuelve un instante en formato correcto.
        /*!
         * Corrige el instante para que cumpla los rangos de días, horas y minutos.
         * En caso que el día no corresponda a ninguno, se asignará como INDEFINIDO.
         */
        void getInstante(void);

    public:
        virtual std::string toString(void);
        virtual bool igual(IInstante *instante);
        virtual bool posterior(IInstante *instante);
        virtual bool previo(IInstante *instante);

        //! Asigna un instante.
        /*!
         * Constructor de la clase. Inicializa los valores para el día, la hora y el
         * minuto.
         */
        Instante(Dia dia = INDEFINIDO, int hora = 0, int minuto = 0);

        //! Convierte un IInstante a Instante.
        /*!
         * Obtiene a partir de un IInstante un Instante.
         * @param  instante El IInstante a convertir.
         * @return El Instante convertido.
         */
        static Instante *toInstante(IInstante *instante);

        //! Obtiene el día del instante.
        /*!
         * Método get para el día del instante.
         * @return El día del instante.
         */
        Dia getDia(void);

        //! Asigna el día del instante.
        /*!
         * Método set para el día del instante.
         * @param dia El nuevo día del instante.
         */
        void setDia(Dia dia);

        //! Obtiene la hora del día.
        /*!
         * Método get para la hora del instante.
         * @return La hora del instante.
         */
        int getHora(void);

        //! Asigna la hora del instante.
        /*!
         * Método set para la hora del instante.
         * @param hora La nueva hora del instante.
         */
        void setHora(int hora);

        //! Obtiene el minuto del instante.
        /*!
         * Método get para el minuto del instante.
         * @return El minuto del instante.
         */
        int getMinuto(void);

        //! Asigna el minuto del instante.
        /*!
         * Método set para el minuto del instante.
         * @param minuto El nuevo minuto del instante.
         */
        void setMinuto(int minuto);
};
#endif
