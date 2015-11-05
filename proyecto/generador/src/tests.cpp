#include <iostream>
#include <string>
#include <sstream>


#include "BD/BD.hh"
#include "BD/Serializacion.hh"
#include "Bloque.hh"
#include "Curso.hh"
#include "Grupo.hh"
#include "Horario.hh" //5
#include "Instante.hh"
#include "Misc.hh"
#include "Periodo.hh"
#include "Plan.hh"
#include "Profesor.hh" //10

#include "BD/BD.cpp"
#include "BD/Serializacion.cpp"
#include "Bloque.cpp"
#include "Curso.cpp"
//#include "Grupo.cpp"
//#include "Horario.cpp"
#include "Instante.cpp"
//#include "Periodo.cpp"
#include "Plan.cpp"
//#include "Profesor.cpp"

int test(void) {
    std::string opcion;
    std::cout << "ELIGA QUE TEST QUIERE CORRER(0 para salir):" << std::endl;
    std::cout << "\t0 - Salir" << std::endl;
    std::cout << "\t1 - Clase Bloque" << std::endl;
    std::cout << "\t2 - Clase Curso" << std::endl;
    std::cout << "\t3 - Clase Grupo" << std::endl;
    std::cout << "\t4 - Clase Horario" << std::endl;
    std::cout << "\t5 - Clase Instante" << std::endl;
    std::cout << "\t6 - Clase Misc" << std::endl;
    std::cout << "\t7 - Clase Periodo" << std::endl;
    std::cout << "\t8 - Clase Plan" << std::endl;
    std::cout << "\t9 - Clase Profesor" << std::endl;
    std::cout << "\t10 - Clase BD" << std::endl;
    std::cout << "\t11 - Clase Serializacion" << std::endl;


    std::cout << "Test # ";
    std::cin >> opcion;

    std::stringstream convert(opcion);
    int respuesta;
    convert>>respuesta;

    return respuesta;
}

int main(void) {
    int elegida = test();
    while (elegida != 0) {
        std::cout << "****INICIO SALIDA*****" << std::endl << std::endl;
        switch (elegida) {
            case 1:
                //testBloque();
                break;
            case 2:
                //testCurso();
                break;
            case 3:
                //testGrupo();
                break;
            case 4:
                //testHorario();
                break;
            case 5:
                testInstante();
                break;
            case 6:
                //testMisc();
                break;
            case 7:
                //testPeriodo();
                break;
            case 8:
                testPlan();
                break;
            case 9:
                //testProfesor();
                break;
            case 10:
                testBD();
                break;
            case 11:
                testSerializacion();
                break;
            default:
                std::cout << "No selecciono un numero adecuado" << std::endl;
        }
        std::cout << std::endl << "****FIN SALIDA*****" << std::endl;
        elegida = test();
    }

}
