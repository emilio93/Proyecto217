/* copyright 2015 palomosFantásticos */

#include <stddef.h>

#include <string>
#include <vector>

#include "Grupo.hh"
#include "Horario.hh"
#include "Misc.hh"

/*******************************************************************************
 ** MÉTODOS PÚBLICOS
 ******************************************************************************/


/*******************************************************************************
 ** MÉTODOS PRIVADOS
 ******************************************************************************/

// NINGUNO POR EL MOMENTO

/**
 * @breif Main para probar la implementación de la clase.
 */
void testHorario(void) {
    using std::cout;
    using std::endl;
    Horario horario = Horario();
    horario.menuPrincipal();
}

void Horario::generarHorario(void) {
    using std::cout;
    using std::endl;

    cout << "Obteniendo planes...";
    std::vector<Plan> *planes = Plan::getPlanes();
    cout << "Listo." << endl;

    for (size_t i = 0; i < planes->size(); i++) {
        cout << "Obteniendo semestres del plan " << planes->at(i).getNombre();
        cout << "...";
        std::vector<Bloque> *bloques = planes->at(i).getBloques();
        cout << "Listo." << endl;

        for (size_t j = 0; j < bloques->size(); j++) {
            cout << "\tObteniendo cursos del semestre ";
            cout << bloques->at(j).getSemestre() << "...";
            std::vector<Curso> *cursos = bloques->at(j).getCursos();
            cout << "Listo." << endl;

            for (size_t k = 0; k < cursos->size(); k++) {
                cout << "\t\tAlistando curso " << cursos->at(k).toString();
                cout << endl;

                cout << "\t\t\tObteniendo profesores para el curso...";
                std::vector<Profesor> *profes = cursos->at(k).getProfesores();
                cout << "Listo. [Profesores obtenidos: " << profes->size();
                cout << "]" << endl;

                cout << "\t\t\tObteniendo posibles horarios para el curso...";
                std::vector< std::vector<IPeriodo*> > *horariosCurso =
                    cursos->at(k).getHorarios();
                cout << "Listo. [Horarios obtenidos: " << horariosCurso->size();
                cout << "]" << endl;

                cout << "Creando los grupos del curso...";
                std::vector<Grupo> *grupos = cursos->at(i).crearGrupos();
                cout << "Listo. [creados: 0, no creados: 0]" << endl;

                /*
                for (int l = 0; l < cursos->at(k).getCantidadGrupos(); l++) {
                    cout << "\t\t\tInicializando grupo " << l+1 << "...";
                    Grupo grupo = Grupo(&cursos->at(k));
                    cout << "Listo." << endl;

                    cout << "\t\t\t\tSeleccionando Horario...No se hace" << endl;
                    cout << "\t\t\t\tSeleccionando Profesor...No se hace" << endl;
                }
                */
            }
        }
    }
}

void Horario::menuPrincipal(void) {
    using std::string;
    using std::cout;
    using std::endl;

    bool horarioCreado = false;

    if (horarioCreado) {
        cout << "ATENCIÓN: En este momento hay un horario creado, si vuelve a ";
        cout << "generar uno sobreescribirá el existente." << endl;
    }

    int it = 0;
    cout << "MENU PRINCIPAL" << endl;
    cout << "¿Que desea hacer?" << endl;

    cout << "\t" << it++ <<" - Generar Horario" << endl;
    cout << "\t" << it++ <<" - Listar Datos" << endl;
    cout << "\t" << it++ <<" - Insertar Datos" << endl;
    cout << "\t" << it++ <<" - Eliminar Datos" << endl;
    cout << "\t" << it++ <<" - Guardar en base de datos" << endl;
    it = 0;
    cout << "\t" << it <<" - Salir" << endl;

    int valor = Misc::solicitarInt("Ingrese un valor");
    switch (valor) {
        case 1:
            this->generarHorario();
            break;
        case 2:
            cout << "Esta opción no está disponible." << endl;
            break;
        case 3:
            cout << "Esta opción no está disponible." << endl;
            break;
        case 4:
            cout << "Esta opción no está disponible." << endl;
            break;
        case 5:
            cout << "Esta opción no está disponible." << endl;
            break;
    }
}
