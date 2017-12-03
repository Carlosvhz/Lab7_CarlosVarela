#include "cliente.h"

/* === Constructor y destructor == */
cliente::cliente(){
}

cliente::cliente(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, string p_direccion, int p_rating)
        :usuario(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono){
  //Username, password, nombre, ID, Edad, Numero de telefono,direccion,rating
  direccion = p_direccion;
  rating = p_rating;
}

cliente::~cliente(){
}


/* === Getters == */
string cliente::getDireccion(){
  return direccion;
}

int cliente::getRating(){
  return rating;
}
