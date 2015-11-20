/* copyright 2015 palomosFantásticos */

#ifndef CLASE_GRUPO
#define CLASE_GRUPO

#include <string>
#include <iostream>
#include <set>
#include <vector>

#include "Curso.hh"
#include "Profesor.hh"
#include "IPeriodo.hh"

//*********************************************************************
// Class: Grupo
//*********************************************************************

//! Class Grupo
/*!
 * La clase grupo contiene información de un grupo de un curso.
 */
class Grupo {
    private:
        int id;
        Curso *curso;//punteros u objetos gente?
        Profesor *profesor;
        std::vector<IPeriodo> *horario;
        int cantidadhoras;
        void elegirProfesor(void);

    public:
        Grupo(int id,Curso *curso, Profesor *profesor);
		int getId(void);
        // devuelve un puntero al curso de este grupo.
        Curso *getCurso(Grupo *GrupoActual);
        // devuelve una lista de profesores disponibles Emilio dijo que se podia
        std::vector<Profesor> getProfesor(Curso *CursoActual);//este método está raro.

        //!
        /*!
         * [setProfesor description]
         * @return  [description]
         */
        bool setProfesor(void);

        void ponerEnHorario(Grupo *GrupoActual);
        // int buscarProfesor(&List<Profesores>);
        // Creo que este busca un
        // profesor de la lista disponible que pueda ser usado para el grupo.
};
#endif
