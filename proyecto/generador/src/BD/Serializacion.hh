#ifndef CLASE_SERIALIZACION
#define CLASE_SERIALIZACION

#include <string>
#include <list>

/**
 * @breif La clase Serializacion se encarga de convertir los resultados de la
 *        base de datos en los objetos pertinentes.
 */
class Serializacion {
    private:
    public:
    	static std::list<Plane> getPlanes(void);
    	static std::list<Bloque> getBloques(Plan * plan);
    	static std::list<Curso> getCursos(Bloque * bloque);
}

#endif
