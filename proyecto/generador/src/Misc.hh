#ifndef CLASE_MISC
#define CLASE_MISC

#include <stddef.h>//This gets NULL

/**
 * @breif Clase de métodos miscelaneos. Se compone de métodos static varios.
 */
class Misc {
    public:

        template<typename T>
        /**
         * @breif Indica si cierto número está dentro de un rango especificado.
         * @param  test      Número del que se determina si se encuentra en el
         *                   rango.
         * @param  min       Límite inferior del rango.
         * @param  max       Límite superior del rango.
         * @param  inclusivo Indica si los límites se incluyen dentro del rango.
         * @return           True si el número se encuentra dentro del rango.
         */
        static boolean enRango(T test, T min, T max, boolean inclusivo = true) {
            if (min > max) {
                T tempMin = min;
                min = max;
                max = tempMin;
            }
            boolean enRango = inclusivo?
                                (test >= min && test <= max)? true: false:
                                (test > min  &&  test < max)? true: false;
            return enRango;
        }
};

#endif