/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"
#include "Profesor.hh"


/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Grupo::Grupo(int id, Curso *curso, Profesor *profesor,
    std::vector<IPeriodo> *horario, int cantidadhoras) {
    this->id = id;
    this->curso = curso;
    this->profesor = profesor;
    this->horario = horario;
    this->cantidadhoras = cantidadhoras;
}

/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

// NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 */
void testGrupo(void) {
    using std::cout;
    using std::endl;
}
