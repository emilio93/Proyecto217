/* copyright 2015 palomosFantásticos */

#ifndef CLASE_MISC
#define CLASE_MISC

#include <stddef.h>

#include <iostream>
#include <string>
#include <sstream>

//! Métodos miscelaneos.
/*!
 * Clase de métodos miscelaneos. Se compone de métodos static varios.
 */
class Misc {
    public:
        template<typename T>
        //! Indica si un número está dentro de un rango.
        /*!
         * Indica si cierto número está dentro de un rango especificado.
         * @param  test      Número del que se determina si se encuentra en el
         *                   rango.
         * @param  min       Límite inferior del rango.
         * @param  max       Límite superior del rango.
         * @param  inclusivo Indica si los límites se incluyen dentro del rango.
         * @return           True si el número se encuentra dentro del rango.
         */
        static bool enRango(T test, T min, T max, bool inclusivo = true) {
            if (min > max) {
                T tempMin = min;
                min = max;
                max = tempMin;
            }
            bool enRango = inclusivo?
                                (test >= min && test <= max)? true: false:
                                (test > min  &&  test < max)? true: false;
            return enRango;
        }

        //! Convierte un objeto a string.
        /*!
         * Convierte un objeto a un string.
         * @param  n Objeto que se convierte.
         * @return   Texto del objeto.
         */
        template <typename T> static std::string to_string(T &n) {
            std::ostringstream stm;
            stm << n;
            return stm.str();
        }
};

void testEnRango(void) {
    using std::cout;
    using std::endl;

    cout << "*** INICIO PRUEBA EN RANGO ***" << endl;
    int a = 5;
    cout << "int a = 5;" << endl;
    int b = 10;
    cout << "int b = 10;" << endl;
    int c = 15;
    cout << "int c = 15;" << endl;
    int d = 15;
    cout << "int d = 15;" << endl;

    if (Misc::enRango(a, b, c)) {
        cout << "a está en el rango de b,c inclusivo." << endl;
    } else {
        cout << "a no está en el rango de b,c inclusivo." << endl;
    }

    if (Misc::enRango(b, a, c)) {
        cout << "b está en el rango de a,b inclusivo." << endl;
    } else {
        cout << "b no está en el rango de a,b inclusivo." << endl;
    }

    if (Misc::enRango(d, a, c)) {
        cout << "d está en el rango de a,c inclusivo." << endl;
    } else {
        cout << "d no está en el rango de a,c inclusivo." << endl;
    }

    if (Misc::enRango(d, a, c, false)) {
        cout << "d está en el rango de a,c exclusivo." << endl;
    } else {
        cout << "d no está en el rango de a,c exclusivo." << endl;
    }
    cout << "*** FIN PRUEBA EN RANGO ***" << endl;
}

void testMisc(void) {
    testEnRango();
}
#endif
