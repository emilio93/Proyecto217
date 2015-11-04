#ifnded CLASE_BD
#define CLASE_BD

#include <string>

/**
 * @breif La clase Serializacion se encarga de convertir los resultados de la
 *        base de datos en los objetos pertinentes.
 */
class Serializacion {
    private:
    public:
	std::List <Planes> getPlanes();
	std::List <Bloques> getBloques();
	std::List <Cursos> getCursos();
}

#endif
