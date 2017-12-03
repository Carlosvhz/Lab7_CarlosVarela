#include "chef.h"
#include "lavaplatos.h"

/* === Constructor y destructor == */
chef::chef(){
}

chef::chef(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, int anio, int p_sueldo, string platillo)
          :personal(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono, anio, p_sueldo){
  //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion, platillo favorito
  platillo_fav = platillo;
}

chef::~chef(){
}


/* === Getters == */
string chef::getPlatillo(){
  return platillo_fav;
}
