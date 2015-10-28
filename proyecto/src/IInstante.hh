#ifndef INTERFACE_INSTANTE
#define INTERFACE_INSTANTE

#include <string>

/**
 * @breif Representación de un instante.
 *
 * Este instante comprende un punto en el sistema temporal en que se trabaje.
 * Contiene operaciones de comparación así como un método para representarse
 * mediante un string.
 */
abstract class IInstante {

    /**
     * @breif Esta es la manera en que el instante se representa mediante un
     *        string característico a si.
     * @return  String qe representa e instante.
     */
    virtual string toString(void);

    /**
     * @breif El operador == indica si dos instantes coinciden en el tiempo.
     */
    virtual boolean operator==(IInstante);

    /**
     * @breif El operador > indica si el instante es posterior al instante con
     *        el cual se compara.
     */
    virtual boolean operator>(IInstante);

    /**
     * @breif El operador < indica si el instante es previo al instante con el
     *        cual se compara.
     */
    virtual boolean operator<(IInstante);
};

#endif
