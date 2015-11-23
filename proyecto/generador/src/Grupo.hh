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

//! La clase grupo contiene información de un grupo de un curso.
/*!
 *
 * Porfavor indicar acá como se comporta la clase.
 */
class Grupo {
     private:
        //! El identificador único del grupo.
        int id;

        //! Es el curso al cual pertenece el grupo.
        Curso *curso;  // punteros u objetos gente?
                       // Puntero está bien.

        //! El profesor asignado al grupo.
        /*!
         * El profesor es elegido por el Grupo, de esta manera no es elegido
         * sino hasta que Grupo realize una serie de comprobaciones,
         * asegurandose que el profesor esté disponible, y notificandole a este
         * la asignación del Grupo.
         */
        Profesor *profesor;

        //! Es el horario en que se imparte el grupo.
        std::vector<IPeriodo*> *horario;

        // Esto viene del curso.
        // int cantidadhoras;

        void elegirProfesor(void);
        
         //! Documentar
        /*!
         * Documentación más extensa
         * @return  Que devuelve el método.
         */
        bool setProfesor(void);

     public:
        //! Asigna el id y el curso del grupo.
        Grupo(int id, Curso *curso);

        //! Documentar
        int getId(void);

        //! Documentar
        void setId(int id);

        //! Documentar
        Curso *getCurso(void);

        // devuelve un puntero al curso de este grupo.
        Curso *getCurso(Grupo *GrupoActual);

        //! Documentar
        void setCurso(Curso *curso);

        //! Documentar
        Profesor *getProfesor(void);

        //! Documentar
        void setProfesor(Profesor *profesor);

        //! Documentar
        std::vector<IPeriodo*> *getHorario(void);

        //! Documentar
        void setHorario(std::vector<IPeriodo*> *horario);


        // devuelve una lista de (posibles) profesores disponibles Emilio dijo
        // que se podia
        // este método está raro.

        //! Devuelve una lista de posibles profesores para dar el grupo.
        std::vector<Profesor> *getPosiblesProfesores(void);

        void ponerEnHorario(Grupo *GrupoActual);
        // int buscarProfesor(&List<Profesores>);
        // Creo que este busca un
        // profesor de la lista disponible que pueda ser usado para el grupo.
};
#endif
