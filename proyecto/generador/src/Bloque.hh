/* copyright 2015 palomosFantásticos */

#ifndef CLASE_BLOQUE
#define CLASE_BLOQUE

#include <iostream>
#include <string>
#include <vector>

#include "Curso.hh"
#include "Plan.hh"

//*********************************************************************
//  Class: Bloque
//*********************************************************************

//! Un Bloque es un conjunto de Cursos recomendados por el Plan de estudios.
/*!
 * El Bloque contiene los cursos que se recomienda que se lleva en un semestre.
 */
class Bloque {
     private:
        //! EL identificador del bloque.
        int id;

        //! El plan al cual pertenece el bloque.
        Plan plan;

        //! El semestre en que se cursa el bloque.
        int semestre;

     public:
         //! Asigna los valores al bloque.
        Bloque(int id, Plan &plan, int semestre);

        //! Método get para el identificador.
        int getId(void);

        //! Método get para el plan al cuál pertenece el bloque.
        Plan getPlan(void);

        //! Método get para el semestre del bloque.
        int getSemestre(void);

        //! Obtiene la lista de cursos del bloque.
        std::vector<Curso> *getCursos(void);  // ocupamos una lista también
};
#endif
