/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <string>
#include <vector>

#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Misc.hh"
#include "Profesor.hh"

/*
COMENTARIOS GENERALES
Lo que sigue, son en general buenas prácticas y en casos alejados se puede no
seguir. Todo(o la mayoría de mi código) sigue lo siguente, es bueno que todo
el código sea homogéneo. Corregí estos aspectos. Puede revisar en el git como
estaba su código.
    -intente a la medida de lo posible, que ninguna linea(comentario o código)
        exceda 80 caracteres.
    -usar camelCase para funciones y variables.
        (https://es.wikipedia.org/wiki/CamelCase por si acaso)
    -Espacio en blanco(" ") entre:
        -funcion y llave: tipoRetorno miFuncion(tipoParam param, ...) {
                              // código
                          }

        -coma y siguiente parámetro: tR mF(tP param1, tP param2, ...) {
        -Secuencias de control y su argumento: "for (...) {", "while (...) {",
            "if (...) {", etc.
        -Entre operadores(no siempre necesario):
            -a = b;
            -if (existe == true)
            -c = 5 * (10+9)  // Operaciones matemáticas se puede omitir esta
                             // regla.
        -Doble slash(//) y comentario: // Mi comentario.
        -DOS ESPACIOS entre código y doble slash: a = 5;  // Asigna 5 a "a".
        -Se me debe estar olvidando algunos casos, los de arriba son los más
            importantes.
    -IMPORTANTE sets y gets.(se los agregué).
    -Renglón en blanco entre funciones.
    -Prefierase usar espacios en vez de tabulaciones(no tan importante).
    -Me parece a mi, que cuando usa *objetoActual, se refiere a this->objeto,
        omitase pasarlo como parámetro.
    -Si se refiere a un atributo de la clase, usese this, para que sea claro que
        se utiliza un miembro de la clase.
 */


/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/

Grupo::Grupo(Curso *curso) {
    this->setCurso(curso);
    
}

int Grupo::getId(void) {
    return this->id;
}

void Grupo::setId(int id) {
    this->id = id;
}

Curso *Grupo::getCurso(void) {
    return this->curso;
}
// Curso *Grupo::getCurso(Grupo *GrupoActual) {
    // *Curso = Serializacion::getCursos(*GrupoActual);  // serialization no
    // tiene un método que le entre "grupo" y diga el curso

    // return *Curso; // devuelve el curso dueño de este grupo supongo que es el
    // puntero del objeto curso que creó este grupo
    //
    // Al Grupo lo crea el Curso, así, el Grupo tiene asignado el Curso cuando
    // es creado. Curso lo crea algo asi.
    // int id = obtenerIdDelGrupoo();
    //
    // Grupo *grupo = new Grupo(id, this);  // ojo que this es un puntero tipo
    //                                      // Curso en este scope.

void Grupo::setCurso(Curso *curso) {
    this->curso = curso;
}

Profesor *Grupo::getProfesor(void) {
    return this->profesor;
}

void Grupo::setProfesor(Profesor *profesor) {
    this->profesor = profesor;
}

std::vector<IPeriodo*> *Grupo::getHorario(void) {
    return this->horario;
}

void Grupo::setHorario(std::vector<IPeriodo*> *horario) {
    this->horario = horario;
}



bool Grupo::setProfesor(void) {  // set al profesor asignado para este grupo
    bool asignado = false;
    std::vector<Profesor> *profesores = this->getPosiblesProfesores();

    for (size_t i = 0; i < profesores->size(); i++) {
        /*
        if (profesores->at(i).estoyDisponible(this->getHorario())) {
            profesores->at(i).asignar(this);
            asignado = true;
            break;
        }
         */
    }

    if (!asignado) {
        // AGREGAR A LISTA DE EXCEPCIONES
    }
    return asignado;
}

void Grupo::ponerEnHorario(Grupo *GrupoActual) {  // crear algo para set en
                                                  // horario..no encuentro
                                                  // ningún archivo con horario.
                                                  // Class horario?? tal vez
}

// vector de objetos o punteros a objeto
// puntero a vector de objetos
std::vector<Profesor> *Grupo::getPosiblesProfesores(void) {
    // Profesor o serialización quien tiene el método?
    // SORRY, MI CULPA, CURSO ES EL QUE LOS DA.
    return this->getCurso()->getProfesores();
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
