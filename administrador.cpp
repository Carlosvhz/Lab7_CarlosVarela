#include "administrador.h"

/* === Constructor y destructor == */
administrador::administrador(){
}

administrador::administrador(string p_username, string p_password, string p_nombre, string p_ID, int p_edad, int p_numeo_telefono, int anio, int p_sueldo)
          :personal(p_username, p_password, p_nombre, p_ID, p_edad, p_numeo_telefono, anio, p_sueldo){
  //Username, password, nombre, ID, Edad, Numero de telefono, año de contratacion, sueldo
  empleadosContratados = 0;
  empleadosDespedidos = 0;
}

administrador::~administrador(){
}


/* === Getters == */
int administrador::getEmpleadosContratados(){
  return empleadosContratados;
}

int administrador::getEmpleadosDespedidos(){
  return empleadosDespedidos;
}
