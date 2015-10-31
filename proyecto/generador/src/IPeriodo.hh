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
     * @breif Destructor por defecto.
     */
    virtual ~IPeriodo() {}

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
     * @breif Indica si dos periodos son iguales, esto es, que
     *        sus instantes iniciales y finales sean iguales.
     */
    virtual bolean igual(IPeriodo);

        /**
     * @breif Indica si un periodo contiene o es el mismo periodo
     *        que el periodo con el cual se está comparando.
     */
    virtual boolean contieneInclusivo(IPeriodo);

        /**
     * @breif Indica si un periodo contiene el periodo con
     *        el cual se está comparando.
     */
    virtual boolean contieneExclusivo(IPeriodo);

    /**
     * @breif Indica si un periodo es el mismo, o está contenido
     *        en el periodo con el cual se está comparando.
     */
    virtual boolean enInclusivo(IPeriodo);

        /**
     * @breif Indica si un periodo está contenido
     *        en el periodo con el cual se está comparando.
     */
    virtual boolean enExclusivo(IPeriodo);

        /**
     * @breif Indica si dos periodos son iguales en duración, esto es, que
     *        la diferencia de sus instantes inicial y final, sea iguales.
     */
    virtual bolean igualDuracion(IPeriodo);

        /**
     * @breif Indica si un periodo es mayor en duración con
     *        respecto al otro periodo.
     */
    virtual boolean mayorDuracion(IPeriodo);

    /**
     * @breif Indica si un periodo es menor en duración con
     *        respecto al otro periodo.
     */
    virtual boolean menorDuracion(IPeriodo);

    /**
     *  @breif Indica si dos periodos tienen un sub-periodo en común. Si el
     *         intante final del primero, es el inicial del segundo, no hay
     *         traslape, esto es, la duración del sub-periodo debe ser mayor a
     *         0.
     * @param  IPeriodo Periodo contra el cual se verifica si hay traslape.
     * @return          Treu en caso que haya traslape, false en caso contrario.
     */
    virtual boolean traslapa(IPeriodo);
};

#endif
