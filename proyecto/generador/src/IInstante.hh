/* copyright 2015 palomosFantásticos */

#ifndef INTERFACE_INSTANTE
#define INTERFACE_INSTANTE

#include <string>

//! Representación de un instante.
/*!
 * Este instante comprende un punto en el sistema temporal en que se trabaje.
 * Contiene operaciones de comparación así como un método para representarse
 * mediante un string.
 */
class IInstante {
    public:
        virtual ~IInstante(void) {;}

        //! Obtiene texto representativo del instante.
        /*!
         * Esta es la manera en que el instante se representa mediante un
         * string característico a si.
         * @return  String que representa e instante.
         */
        virtual std::string toString(void) = 0;

        //! Indica si dos instantes coinciden en el tiempo.
        /*!
         * Indica si dos instantes coinciden en el tiempo.
         * @param instante Instante con el que se compara.
         */
        virtual bool igual(IInstante *instante) = 0;

        //! Indica si el instante es posterior a otro.
        /*!
         * Indica si el instante es posterior al instante con
         * el cual se compara.
         * @param instante Instante con el que se compara.
         */
        virtual bool posterior(IInstante *instante) = 0;

        //! Indica si el instante es previo a otro.
        /*!
         * Indica si el instante es previo al instante con el
         * cual se compara.
         * @param instante Instante con el que se compara.
         */
        virtual bool previo(IInstante *instante) = 0;
};

#endif
