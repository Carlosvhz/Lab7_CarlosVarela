#include "personal.h"

/* === Constructor y destructor == */
personal::personal(){
}

personal::personal(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, int anio, int p_sueldo)
          :usuario(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono){
  //Username, password, nombre, ID, Edad, Numero de telefono, año de contratacion, sueldo
  anio_contratacion = anio;
  sueldo = p_sueldo;
}

personal::~personal(){
}


/* === Getters == */
int personal::getContratacion(){
  return anio_contratacion;
}

int personal::getSueldo(){
  return sueldo;
}
