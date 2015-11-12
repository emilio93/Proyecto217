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
//#include "Grupo.cpp" //5
//#include "Horario.cpp"
#include "Instante.cpp"
#include "Periodo.cpp"
#include "Plan.cpp"
//#include "Profesor.cpp" //10

//! Menú del programa para probar las clases.
int test(void) {
    using namespace std;

    string opcion;
    cout << "ELIGA QUE TEST QUIERE CORRER(0 para salir):" << endl;
    cout << "\t0 - Salir" << endl;
    cout << "\t1 - Clase Bloque" << endl;
    cout << "\t2 - Clase Curso" << endl;
    cout << "\t3 - Clase Grupo" << endl;
    cout << "\t4 - Clase Horario" << endl;
    cout << "\t5 - Clase Instante" << endl;
    cout << "\t6 - Clase Misc" << endl;
    cout << "\t7 - Clase Periodo" << endl;
    cout << "\t8 - Clase Plan" << endl;
    cout << "\t9 - Clase Profesor" << endl;
    cout << "\t10 - Clase BD" << endl;
    cout << "\t11 - Clase Serializacion" << endl;

    cout << "Test # ";
    cin >> opcion;

    stringstream convert(opcion);
    int respuesta;
    convert >> respuesta;

    return respuesta;
}

//! Programa para probar las clases.
int main(void) {
    using namespace std;

    int elegida = test();
    while (elegida != 0) {
        cout << "****INICIO PRUEBA*****" << endl << endl;
        switch (elegida) {
            case 1:
                //testBloque();
                break;
            case 2:
                testCurso();
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
                testMisc();
                break;
            case 7:
                testPeriodo();
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
                cout << "No selecciono un numero adecuado" << endl;
        }
        cout << endl << "****FIN PRUEBA*****" << endl;
        elegida = test();
    }
}
