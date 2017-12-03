#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "personal.h"

class administrador:public personal{

  private:
    int empleadosContratados, empleadosDespedidos;

  public:
    //Constructor y desctructor
    administrador();
    administrador(string,string,string,string,int,int,int,int);
              //Username, password, nombre, ID, Edad, Numero de telefono, año_contratacion, sueldo
    virtual~administrador();
    //Getters
    int getEmpleadosContratados();
    int getEmpleadosDespedidos();

};

#endif
