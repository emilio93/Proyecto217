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
string diaToString(Dia dia) {
  string str = "";
  switch (dia) {
    case LUNES:
      str = "lunes";
      break;
    case MARTES:
      str = "martes";
      break;
    case MIERCOLES:
      str = "miercoles";
      break;
    case JUEVES:
      str = "jueves";
      break;
    case VIERNES:
      str = "viernes";
      break;
    case SABADO:
      str = "sabado";
      break;
    case DOMINGO:
      str = "domingo";
      break;
    case INDEFINIDO:
      str = "indefinido";
      break;
  }
  return str;
}

#endif ENUM_DIA
