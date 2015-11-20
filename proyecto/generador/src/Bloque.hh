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
        int id;
        Plan plan;
        int semestre;
    public:
<<<<<<< HEAD
        Bloque(int id, Plan &plan, int semestre);
=======
        Bloque(int &id, Plan &plan, int &semestre);
>>>>>>> 888e23643ae905a31ef9234e9ba78fb9464ce27d
        int getId(void);
        int getSemestre(void);

        //! Set de cursos
        /*! \brief
         *  \return
        */
        // std::set<Curso> cursos;
        // nosotros treamos la lista de cursos de la base de datos no los
        // ponemos
        std::vector<Curso> *getCursos(void);  // ocupamos una lista también
};
#endif
