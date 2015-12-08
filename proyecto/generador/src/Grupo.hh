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
 *  La clase tendra un puntero al curso al que pertence y obtendra
 * un puntero de profesor que se asignará según disponibilidad.
 * Además de aquí se obtendrá el algoritmo de asignación y de los cursos excepción
 * Por otro lado grupo
 */
class Grupo {
     private:
        //! El identificador único del grupo.
        int id;

        //! Es el curso al cual pertenece el grupo.
        Curso *curso;

        //! El profesor asignado al grupo.
        /*!
         * El profesor es elegido por el Grupo, de esta manera no es elegido
         * sino hasta que Grupo realize una serie de comprobaciones,
         * asegurandose que el profesor esté disponible, y notificandole a este
         * la asignación del Grupo.
         */
        Profesor *profesor;

        //! Es el horario en que se dan las clases del grupo.
        std::vector< std::vector<IPeriodo*> > *horario;


        /*! Lista de grupo que no obtuvieron profesor y
         * por lo tanto dicho curso no tiene profesor para esta
         * instancia de grupo
		*/
        std::vector<Curso*> *grupo_sin_profesor;


     public:
        //! Asigna el id y el curso del grupo.
        /*!
         * Un constructor que acepta el curso del cual es.
         * @param curso El curso del cual es el Grupo.
         */
        Grupo(Curso *curso);

		/*!
         * asigna el profesor disponible al curso.
         *@return un booleano que indica si se pudo asignar el profesor.
         */
        bool asignarProfesor(void);

        //! Trae id del grupo.
        int getId(void);

        //! Asigna el id del grupo.
        void setId(int id);

        //! Obtiene el puntero al curso dueño de este grupo.
        Curso *getCurso(void);

        //! Asigna el curso obtenido a este curso.
        void setCurso(Curso *curso);

        //! Obtiene el puntero a profesor.
        Profesor *getProfesor(void);

        //! Asigna el profesor al profesor del curso.
        void setProfesor(Profesor *profesor);

        //! Obtiene vector de periodos para este curso.
        std::vector< std::vector<IPeriodo*> > *getHorario(void);

        //! Asigna el horario del grupo.
        void setHorario(std::vector< std::vector<IPeriodo*> > *horario);

        //! Asigna ese horario en el vector de punteros a
        //! Iperiodo con el puntero obtenido en getHorario.
        void setHorario(std::vector<IPeriodo*> *horario);

        //! Obtiene un puntero al vector con la lista de
        //! profesores disponibles para el grupo.
        std::vector<Profesor> *getPosiblesProfesores(void);
};
#endif
