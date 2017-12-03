#include "mesero.h"

/* === Constructor y destructor == */
mesero::mesero(){
}

mesero::mesero(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, int anio, int p_sueldo)
          :personal(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono, anio, p_sueldo){
  //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion
}

mesero::~mesero(){
}


/* === Getters == */
string mesero::getPlatillo(int numero){
  return platillos.at(numero);
}

vector<string> mesero::getPlatillos(){
  return platillos;
}

void mesero::eliminarPlatillo(int numero){
  platillos.erase(platillos.begin()+numero);
}
void mesero::eliminarPlatillos(){
  for(int i=0; i<platillos.size(); i++){
    platillos.erase(platillos.begin()+i);
  }
}

void mesero::setPlatillo(string platillo){
  platillos.push_back(platillo);
}
