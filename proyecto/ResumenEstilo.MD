#Convenciones del proyecto

##Este documento
Se despliega acá las reglas generales a utilizar en el código C++ según el estilo propuesto por
Google en https://google-styleguide.googlecode.com/svn/trunk/cppguide.html.

No debe considerarse esto como una fuente fidedigna.

##Introducción
La idea de apegarnos a un estilo de programación se concentra en la legibilidad del código, así como
en la facilidad para el debugueo y la estandarización de nuestro código. Se le da más importancia a 
la legibilidad del código que a lo que puede ser la eficiencia de este, sin dejarlo de lado cuando 
es posible.(Ver sección [Background](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Background))

##Sobre los #define
Se utilizan para evitar la multiple inclusión de archivos. Se utiliza de la siguiente manera:
```C++
#ifndef MI_ELEMENTO
#define MI_ELEMENTO
//...código
#endif
```

##Parámetros de las funciones
Si es el caso, se asignan primero los parámetros de entrada y luego los de salida.

##Inclusión de archivos
Se debe seguir el orden de importación como sigue: librerias de C. librerias de C++, otras librerias, archivos del proyecto.

##Declaración de variables locales
Se intenta declarar las variables en el mínimo "scope" necesario, y de manera que el uso
de la varibale no esté alejado de su declaración. Además iniciarlizarlas tan pronto como sea posible, ojalá en 
la declaración.
```C++
//mal
int miVariable;
miVariable = obtenerValor();
```

```C++
//bien
int miVariable = obtenerValor();
```
(Ver sección [Local Variables](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Local_Variables))


##Nombres de los elementos
