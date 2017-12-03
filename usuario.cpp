#include "usuario.h"

/* === Constructor y destructor == */
usuario::usuario(){
}

usuario::usuario(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono){
        //Username, password, nombre, ID, Edad, Numero de telefono
  username = p_username;
  password = p_password;
  nombre = p_nombre;
  ID = p_ID;
  edad = p_edad;
  numero_telefono = p_numeo_telefono;
}

usuario::~usuario(){
}


/* === Getters == */
string usuario::getUsername(){
  return username;
}

string usuario::getPassword(){
  return password;
}

string usuario::getNombre(){
  return nombre;
}

string usuario::getID(){
  return ID;
}

int usuario::getEdad(){
  return edad;
}

int usuario::getNumeroTelefono(){
  return numero_telefono;
}
