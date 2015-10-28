#ifndef INTERFACE_PERIODO
#define INTERFACE_PERIODO

/**
 * @breif Representación de un periodo continuo.
 *
 * Este perido puede indicar su Instante de inicio así como su final. Además
 * tiene distintas maneras de compararse con otros periodos. Si se requiere
 * otro tipo de comparación este debe realizarse mediante los métodos de
 * comparación que se especifican en IInstante.
 */
abstract class IPeriodo {

    /**
     * @breif Devuelve el Instante inicial del periodo. Se debe asegurar que
     *        el instante inicial previo al final.
     * @return  El instante inicial del periodo.
     */
    virtual IInstante getInicio(void);

    /**
     * @breif Devuelve el Instante final del periodo. Se debe asegurar que el
     *        instante inicial es posterior al inicial
     * @return  El instante final del periodo.
     */
    virtual IInstante getFinal(void);

    /**
     * @breif El operador == indica si dos periodos son iguales, esto es, que
     *        sus instantes iniciales y finales sean iguales.
     */
    virtual bolean operator==(void);

    /**
     * @breif El operador >= indica si un periodo contiene o es el mismo periodo
     *        que el periodo con el cual se está comparando.
     */
    virtual boolean operator>=(IPeriodo);

    /**
     * @breif El operador <= indica si un periodo es el mismo, o está contenido
     *        en el periodo con el cual se está comparando.
     */
    virtual boolean operator<=(IPeriodo);

    /**
     * @breif El operador > indica si un periodo es mayor en duración con
     *        respecto al otro periodo.
     */
    virtual boolean operator>(IPeriodo);

    /**
     * @breif El operador < indica si un periodo es menor en duración con
     *        respecto al otro periodo.
     */
    virtual boolean operator<(IPeriodo);
};

#endif
