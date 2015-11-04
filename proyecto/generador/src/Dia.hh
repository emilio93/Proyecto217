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

int diaToInt(Dia dia) {
  int d = 0;
  switch (dia) {
    case LUNES:
        d = 1;
        break;
    case MARTES:
        d = 2;
        break;
    case MIERCOLES:
        d = 3;
        break;
    case JUEVES:
        d = 4;
        break;
    case VIERNES:
        d = 5;
        break;
    case SABADO:
        d = 6;
        break;
    case DOMINGO:
        d = 7;
        break;
    case INDEFINIDO:
        d = 0;
        break;
  }
  return d;
}

Dia intToDia(int dia) {
  Dia d = INDEFINIDO;
  switch (dia) {
    case 1:
        d = LUNES;
        break;
    case 2:
        d = MARTES;
        break;
    case 3:
        d = MIERCOLES;
        break;
    case 4:
        d = JUEVES;
        break;
    case 5:
        d = VIERNES;
        break;
    case 6:
        d = SABADO;
        break;
    case 7:
        d = DOMINGO;
        break;
    case 0:
        d = INDEFINIDO;
        break;
  }
  return d;
}

#endif
