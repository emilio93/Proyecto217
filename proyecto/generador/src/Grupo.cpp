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

Grupo::Grupo(int id, Curso *curso, Profesor *profesor){
    this->id = id;
    this->curso = curso;
    this->profesor = profesor;

}
int Grupo::getId(void){
	return this->id;
}
Curso *Grupo::getCurso(Grupo *GrupoActual){

	//*Curso = Serializacion::getCursos(*GrupoActual);//serialization no tiene un método que le entre "grupo" y diga el curso

	return *Curso; // devuelve el curso dueño de este grupo supongo que es el puntero del objeto curso que creo este grupo
}

bool Grupo::setProfesor(void){ //set al profesor asignado para este grupo

    bool asignado = false;
    std::vector<Profesor> *profesores = Profesor::getProfesores(this->getCurso());

    for (size_t i = 0; i < profesores->size(); i++) {
        if (profesores->at(i).estoyDisponible(this->getHorario())) {
            profesores->at(i).asignar(this);
            asignado = true;
            break;
        }
    }

    if (!asignado) {
        // AGREGAR A LISTA DE EXCEPCIONES
    }
    return asignado;
}
void Grupo::ponerEnHorario(Grupo *GrupoActual){//crear algo para set en horario..no encuentro ningun archivo con horario.
	//Class horario?? tal vez

}
std::vector<Profesor> Grupo :: getProfesor(Curso *CursoActual){//vector de objetos o punteros a objeto
	//Profesor o serialización quien tiene el método?
	return Serializacion::getProfesor(Curso *CursoActual);
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
