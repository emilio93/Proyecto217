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
        Curso *curso;  
      
        //! El profesor asignado al grupo.
        /*!
         * El profesor es elegido por el Grupo, de esta manera no es elegido
         * sino hasta que Grupo realize una serie de comprobaciones,
         * asegurandose que el profesor esté disponible, y notificandole a este
         * la asignación del Grupo.
         */
        Profesor *profesor;
	
      
        std::vector<IPeriodo*> *horario;
		//! Es el horario en que se imparte el grupo.
  
        bool setProfesor(void);
        /*!
         * asigna el profesor disponible al curso.
         *@return un booleano que indica si se pudo asignar el profesor.
         */
         
		std::vector<Listaexcepciones*> *curso_sin_profesor; 
		/*!no creo que esto sea bueno puntero a puntero 
		pero necesito un lugar donde guardar los objetos curso
		que no tienen profe
		*/
		
		
     public:
        
        Grupo(int id, Curso *curso);
		//! Asigna el id y el curso del grupo.
     
        int getId(void);
		//! trae id del grupo
       
        Grupo *setId(int id);
		//! asigna el id del grupo
        
        Curso *getCurso(void);
		//! obtiene el puntero al curso dueño de este grupo.
       
        Grupo *setCurso(Curso *curso);
		//! asigna el curso obtenido a este curso
        
        Profesor *getProfesor(void);
		//! obtiene el puntero a profesor
        
        Grupo *setProfesor(Profesor *profesor);
		//! asigna el profesor al profesor del curso
             
        std::vector<IPeriodo*> *getHorario(void);
		//!obtiene puntero a vector de punteros Iperiodo
       
        Grupo *setHorario(std::vector<IPeriodo*> *horario);
		//! asigna ese horario en el vector de punteros a 
		//! Iperiodo con el puntero obtenido en *getHorario

        std::vector<Profesor> *getPosiblesProfesores(void);
		//! obtiene un puntero al vector con la lista de 
		//! profesores disponibles para el grupo
		
		        
};
#endif
