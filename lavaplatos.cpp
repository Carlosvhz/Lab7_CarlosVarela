#include "lavaplatos.h"
#include "chef.h"

/* === Constructor y destructor == */
lavaplatos::lavaplatos(){
}

lavaplatos::lavaplatos(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, int anio, int p_sueldo)
          :personal(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono, anio, p_sueldo){
  //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion, platillo favorito
  motivacion = 50;
}

lavaplatos::~lavaplatos(){
}


/* === Getters == */
int lavaplatos::getMotivacion(){
  return motivacion;
}

void lavaplatos::setMotivacion(int numero){
  motivacion = numero;
}

void lavaplatos::desmotivar(int numero){
  motivacion-=numero;
}

void lavaplatos::motivar(int numero){
  motivacion+=numero;
}
