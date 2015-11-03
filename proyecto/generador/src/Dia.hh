#ifndef ENUM_DIA
#define ENUM_DIA

#include <string>

/**
 * @breif Días de la semana e indefinido que representa cualquier día.
 *        De esta manera, indefinido no se puede comparar con los otros días.
 */
enum Dia {
    LUNES       = 1,
    MARTES      = 2,
    MIERCOLES   = 3,
    JUEVES      = 4,
    VIERNES     = 5,
    SABADO      = 6,
    DOMINGO     = 7,
    INDEFINIDO  = 0
};

/**
 * @breif Este método devuelve un string en minúsculas con el día que se pasa
 *        por parámetro.
 * @param  dia Dia del que se requiere el string.
 * @return     String del día que se requiere.
 */
std::string diaToString(Dia dia) {
  std::string str = "";
  switch (dia) {
    case LUNES: str = "lunes";
    case MARTES: str = "martes";
    case MIERCOLES: str = "miercoles";
    case JUEVES: str = "jueves";
    case VIERNES: str = "viernes";
    case SABADO: str = "sabado";
    case DOMINGO: str = "domingo";
    case INDEFINIDO: str = "indefinido";
  }
  return str;
}

int diaToInt(Dia dia) {
  int d = 0;
  switch (dia) {
    case LUNES: d = 1;
    case MARTES: d = 2;
    case MIERCOLES: d = 3;
    case JUEVES: d = 4;
    case VIERNES: d = 5;
    case SABADO: d = 6;
    case DOMINGO: d = 7;
    case INDEFINIDO: d = 0;
  }
  return d;
}

Dia intToDia(int dia) {
  Dia d = INDEFINIDO;
  switch (dia) {
    case 1: d = LUNES;
    case 2: d = MARTES;
    case 3: d = MIERCOLES;
    case 4: d = JUEVES;
    case 5: d = VIERNES;
    case 6: d = SABADO;
    case 7: d = DOMINGO;
    case 0: d = INDEFINIDO;
  }
  return d;
}

#endif
