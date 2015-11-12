#Tareas
ESTO NO ES DEFINITIVO, LEANLO TODO Y OPINEN SI HACE FALTA ALGO, SI ESTÁ BIEN,
SI ESTÁ MAL O SI SOBRA ALGO.

Ojo que el doxygen no funciona bien si se usa el comando doxygen. Se tiene que
usar como make doxy(revisen el make si quieren saber porque).

Noten como se incluyen cosas, premero librerias estándares, luego otras
librerías(Como en Serializacion o BD) y al final archivos del proyecto. Un poco
tonto y tedioso, pero a la larga es útil.

using namespace std no debe usarse en clases, se puede usar en métodos que no
sean de ninguna clase, y el ámbito donde se encuentra debería ser reducido.
Por ejemplo en las funciones test. ejemplo
```
void testMiObjeto(void) {
    using namespace std;
    // Código superpichudo que llama mucho a std::cout
} // acá afuera ya no se puede usar std.
```

##Tareas Generales
* Todos tenemos que estar muy al tanto del código o sino, al menos saber que hace
    cada unidad(clases, métodos)

* Asegurarse de saber como está funcionando el makefile, como jala las librerías.
* Despreocuparse del proposito del programa, y preocuparse por la ocupación
    individual de cada unidad.

* Hacer commits constantemente con cada cambio que hagan, esto ayuda mucho a saber
    que han hecho. ejemplo, si terminé de documentar una clase, hacer un commit
    diciendo que documente X clase. Continuar en otra cosa.

##Tareas específicas
* Documentar proceso de compilación. Indicando pasos necesarios(MySQL, cpp,
    mysqlconnect, etc...etc) y pasos opcionales(apache, php, phpmyadmin).

* Llenar base de datos para pruebas.

* Anotar métodos que necesita Serializacion, puede ser en el header, pero
    indicar que no se ha implementado.

* Implementarse de ser posible. Se puede implementar INCOMPLETAMENTE si se
    indica que hace falte. ejemplo
    ```
    /**
     * @TODO Falta jalar tales y tales datos de la base de datos.
     * @TODO Falta poner objetos en una coleccion(vector, list, etc)
     */
    ```
    Para que compile, pueden devolver un valor 'quemado', ejemplo
    ```
    reuturn NULL;//necesita stddef.h, esto es #include <stddef.h>
    return false;
    ```

* Documentar BIEN las clases(Véase Curso). ESTO ES MUY MUY IMPORTANTE.
    Esto requiere que se piense fuera del programa que hace cada objeto, como si
    viviera en el mundo real y no en la computadora.

* Documentar métodos. Con solo ver el doxy deberíase saber que clases y métodos
    hay y que hacen.

* Terminar TENTATIVAMENTE Curso, revisar los TODO's

* Implementar Periodo. Se puede usar Instante(e IInstante) como ayuda. Entender
    las interfaces para poder hacer esto.

* Arreglar los siguientes headers. Bloque, Grupo, Horario, Plan, Profesor.

* Sería genial si se les ocurre algo más.
